#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <math.h>

// 可配置参数
#define CABINET_SIZE 50
#define NUM_COURIERS 3
#define NUM_STUDENTS 10
#define STUDENT_MIN_SLEEP 2  // 学生最小睡眠时间(秒)
#define STUDENT_MAX_SLEEP 4  // 学生最大睡眠时间(秒)
#define STATS_INTERVAL 5     // 统计信息更新间隔(秒)
#define MAX_LOG_LINES 100    // 最大日志行数
#define MONITOR_INTERVAL 2   // 监控线程检查间隔(秒)

// 快递员效率配置 (每个快递员的投递间隔范围，单位毫秒)
int courier_efficiency[NUM_COURIERS][2] = {
    {100, 200},   // 快递员1: 100-200毫秒
    {100, 150},   // 快递员2: 200-300毫秒
    {100, 300}    // 快递员3: 300-400毫秒
};

// ANSI 颜色代码
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET "\x1b[0m"

// 快递结构
typedef struct {
    int parcel_id;      // 快递编号
    int student_id;     // 收件人ID
    int courier_id;     // 快递员ID
    struct timeval timestamp;   // 存放时间戳(毫秒级)
} Parcel;

// 日志条目结构
typedef struct {
    char message[256];  // 日志消息
    struct timeval timestamp;   // 日志时间戳(毫秒级)
    int is_warning;     // 是否为警告消息
} LogEntry;

// 统计信息结构
typedef struct {
    long total_delivered;    // 总投递数量
    long total_picked;       // 总取件数量
    double in_rate;          // 输入速率(件/分钟)
    double out_rate;         // 输出速率(件/分钟)
    struct timeval last_stat_time;   // 上次统计时间(毫秒级)
    long last_delivered;     // 上次统计时的投递量
    long last_picked;        // 上次统计时的取件量
    long courier_stats[NUM_COURIERS]; // 每个快递员的投递量
    long long total_delivery_time; // 总投递时间(微秒)
    long delivery_count;      // 投递次数
} StatsData;

// 屏幕尺寸
struct winsize terminal_size;

// 共享数据结构
typedef struct {
    Parcel cabinet[CABINET_SIZE];   // 快递柜
    int parcel_count;               // 当前快递数量
    int parcel_counter;             // 快递ID计数器
    LogEntry log_queue[MAX_LOG_LINES]; // 日志队列
    int log_count;                  // 日志条目计数
    StatsData stats;                // 统计信息
    int is_full;                    // 快递柜是否已满
    int couriers_waiting;           // 等待中的快递员数量
    int students_waiting;           // 等待中的学生数量
    int recovery_mode;              // 系统恢复模式
    
    pthread_mutex_t mutex;          // 主互斥锁
    pthread_cond_t not_full;        // 快递柜未满条件
    pthread_cond_t not_empty;       // 快递柜非空条件
    pthread_mutex_t log_mutex;      // 日志互斥锁
} SharedData;

// 获取当前时间(毫秒级)
void get_current_time(struct timeval *tv) {
    gettimeofday(tv, NULL);
}

// 计算时间差(毫秒)
long time_diff(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000 + 
           (end->tv_usec - start->tv_usec) / 1000;
}

// 获取终端大小
void get_terminal_size() {
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal_size) == -1) {
        terminal_size.ws_row = 24; // 默认24行
        terminal_size.ws_col = 80; // 默认80列
    }
}

// 初始化共享数据
void init_shared_data(SharedData *data) {
    data->parcel_count = 0;
    data->parcel_counter = 1;
    data->log_count = 0;
    data->is_full = 0;
    data->couriers_waiting = 0;
    data->students_waiting = 0;
    data->recovery_mode = 0;
    
    // 初始化统计信息
    data->stats.total_delivered = 0;
    data->stats.total_picked = 0;
    data->stats.in_rate = 0.0;
    data->stats.out_rate = 0.0;
    get_current_time(&data->stats.last_stat_time);
    data->stats.last_delivered = 0;
    data->stats.last_picked = 0;
    data->stats.total_delivery_time = 0;
    data->stats.delivery_count = 0;
    for (int i = 0; i < NUM_COURIERS; i++) {
        data->stats.courier_stats[i] = 0;
    }
    
    // 初始化快递柜格子
    for (int i = 0; i < CABINET_SIZE; i++) {
        data->cabinet[i].parcel_id = 0; // 0表示空位
    }
    
    pthread_mutex_init(&data->mutex, NULL);
    pthread_cond_init(&data->not_full, NULL);
    pthread_cond_init(&data->not_empty, NULL);
    pthread_mutex_init(&data->log_mutex, NULL);
}

// 添加日志条目
void add_log(SharedData *data, const char *msg, int is_warning) {
    pthread_mutex_lock(&data->log_mutex);
    
    LogEntry entry;
    get_current_time(&entry.timestamp);
    strncpy(entry.message, msg, sizeof(entry.message) - 1);
    entry.message[sizeof(entry.message) - 1] = '\0';
    entry.is_warning = is_warning;
    
    if (data->log_count < MAX_LOG_LINES) {
        data->log_queue[data->log_count] = entry;
        data->log_count++;
    } else {
        // 队列已满，移除最旧的日志
        for (int i = 0; i < MAX_LOG_LINES - 1; i++) {
            data->log_queue[i] = data->log_queue[i + 1];
        }
        data->log_queue[MAX_LOG_LINES - 1] = entry;
    }
    
    pthread_mutex_unlock(&data->log_mutex);
}

// 更新统计信息
void update_stats(SharedData *data) {
    struct timeval now;
    get_current_time(&now);
    
    // 计算时间差(秒)
    double elapsed = (now.tv_sec - data->stats.last_stat_time.tv_sec) +
                    (now.tv_usec - data->stats.last_stat_time.tv_usec) / 1000000.0;
    
    if (elapsed >= STATS_INTERVAL) {
        // 计算速率（件/分钟）
        long delivered_diff = data->stats.total_delivered - data->stats.last_delivered;
        long picked_diff = data->stats.total_picked - data->stats.last_picked;
        
        data->stats.in_rate = (delivered_diff / elapsed) * 60;
        data->stats.out_rate = (picked_diff / elapsed) * 60;
        
        // 更新上次统计值
        data->stats.last_delivered = data->stats.total_delivered;
        data->stats.last_picked = data->stats.total_picked;
        data->stats.last_stat_time = now;
    }
}

// 快递员线程函数
void *courier_thread(void *arg) {
    // 解析参数
    void **params = (void **)arg;
    SharedData *data = (SharedData *)params[0];
    int courier_id = (int)(long)params[1];
    int min_sleep = courier_efficiency[courier_id][0];
    int max_sleep = courier_efficiency[courier_id][1];
    
    free(arg); // 释放参数内存
    
    while (1) {
        // 根据快递员效率随机睡眠(毫秒)
        int sleep_time = min_sleep + rand() % (max_sleep - min_sleep + 1);
        usleep(sleep_time * 1000); // 转换为微秒
        
        struct timeval start_time;
        get_current_time(&start_time);
        
        pthread_mutex_lock(&data->mutex);
        
        // 记录实际等待时间
        struct timeval end_time;
        get_current_time(&end_time);
        long actual_wait = time_diff(&start_time, &end_time);
        data->stats.total_delivery_time += actual_wait;
        data->stats.delivery_count++;
        
        // 更新统计信息
        update_stats(data);
        
        // 等待快递柜有空位
        while (data->parcel_count >= CABINET_SIZE) {
            // 如果是第一次满，记录警告
            if (!data->is_full) {
                data->is_full = 1;
                char msg[256];
                snprintf(msg, sizeof(msg), "警告: 快递柜已满! (使用率: %d%%)", 
                         (data->parcel_count * 100) / CABINET_SIZE);
                add_log(data, msg, 1);
            }
            
            // 记录等待状态
            data->couriers_waiting++;
            char msg[256];
            snprintf(msg, sizeof(msg), "快递员 %d 等待空位...", courier_id);
            add_log(data, msg, 0);
            
            // 等待条件变量
            pthread_cond_wait(&data->not_full, &data->mutex);
            
            // 结束等待
            data->couriers_waiting--;
        }
        
        // 找到空柜格
        int slot = -1;
        for (int i = 0; i < CABINET_SIZE; i++) {
            if (data->cabinet[i].parcel_id == 0) {
                slot = i;
                break;
            }
        }
        
        if (slot == -1) {
            pthread_mutex_unlock(&data->mutex);
            continue;
        }
        
        // 创建新快递
        Parcel parcel;
        parcel.parcel_id = data->parcel_counter++;
        
        // 确保学生ID在1到NUM_STUDENTS之间
        parcel.student_id = (rand() % NUM_STUDENTS) + 1; 
        
        parcel.courier_id = courier_id;
        get_current_time(&parcel.timestamp);
        
        // 放入快递柜
        data->cabinet[slot] = parcel;
        data->parcel_count++;
        data->stats.total_delivered++;
        data->stats.courier_stats[courier_id]++;
        
        // 重置满状态标志
        data->is_full = 0;
        
        // 记录日志
        char time_buf[64];
        struct tm *timeinfo = localtime(&parcel.timestamp.tv_sec);
        strftime(time_buf, sizeof(time_buf), "%H:%M:%S", timeinfo);
        int ms = parcel.timestamp.tv_usec / 1000;
        char msg[256];
        snprintf(msg, sizeof(msg), "快递员 %d: 快递 %d 投递 (收件人: %d) 时间: %s.%03d",
                 courier_id, parcel.parcel_id, parcel.student_id, time_buf, ms);
        add_log(data, msg, 0);
        
        // 通知学生有新快递
        pthread_cond_broadcast(&data->not_empty);
        
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

// 学生线程函数
void *student_thread(void *arg) {
    // 解析参数
    void **params = (void **)arg;
    SharedData *data = (SharedData *)params[0];
    int student_id = (int)(long)params[1];
    
    free(params); // 释放参数内存
    
    while (1) {
        // 随机睡眠2~4秒
        int sleep_time = STUDENT_MIN_SLEEP + rand() % (STUDENT_MAX_SLEEP - STUDENT_MIN_SLEEP + 1);
        usleep(sleep_time * 1000000); // 转换为微秒
        
        pthread_mutex_lock(&data->mutex);
        
        // 更新统计信息
        update_stats(data);
        
        // 检查是否有自己的快递
        int slot = -1;
        for (int i = 0; i < CABINET_SIZE; i++) {
            if (data->cabinet[i].parcel_id != 0 && 
                data->cabinet[i].student_id == student_id) {
                slot = i;
                break;
            }
        }
        
        // 没有快递则等待
        while (slot == -1) {
            // 记录等待状态
            data->students_waiting++;
            char msg[256];
            snprintf(msg, sizeof(msg), "学生 %d 等待快递", student_id);
            add_log(data, msg, 0);
            
            pthread_cond_wait(&data->not_empty, &data->mutex);
            
            // 结束等待
            data->students_waiting--;
            
            // 被唤醒后重新检查
            for (int i = 0; i < CABINET_SIZE; i++) {
                if (data->cabinet[i].parcel_id != 0 && 
                    data->cabinet[i].student_id == student_id) {
                    slot = i;
                    break;
                }
            }
        }
        
        // 取快递
        Parcel parcel = data->cabinet[slot];
        data->cabinet[slot].parcel_id = 0; // 清空格子
        data->parcel_count--;
        data->stats.total_picked++;
        
        // 计算存放时长(毫秒)
        struct timeval now;
        get_current_time(&now);
        long duration = (now.tv_sec - parcel.timestamp.tv_sec) * 1000 + 
                       (now.tv_usec - parcel.timestamp.tv_usec) / 1000;
        
        // 记录日志
        char msg[256];
        snprintf(msg, sizeof(msg), "学生 %d: 取件 %d (快递员: %d) 存放时长: %ld毫秒",
                 student_id, parcel.parcel_id, parcel.courier_id, duration);
        add_log(data, msg, 0);
        
        // 通知快递员有空位
        pthread_cond_broadcast(&data->not_full);
        
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

// 监控线程函数 - 防止系统死锁
void *monitor_thread(void *arg) {
    SharedData *data = (SharedData *)arg;
    
    while (1) {
        sleep(MONITOR_INTERVAL); // 每2秒检查一次
        
        pthread_mutex_lock(&data->mutex);
        
        // 检测潜在死锁：快递柜满且有快递员等待，但没有学生取件
        if (data->parcel_count >= CABINET_SIZE && 
            data->couriers_waiting > 0 && 
            data->students_waiting == 0) {
            
            // 进入恢复模式
            data->recovery_mode = 1;
            char msg[256];
            snprintf(msg, sizeof(msg), 
                     ANSI_COLOR_RED "监控: 检测到潜在死锁! 快递柜满(%d/%d), %d快递员等待, %d学生等待. 激活恢复模式..." ANSI_COLOR_RESET,
                     data->parcel_count, CABINET_SIZE, 
                     data->couriers_waiting, data->students_waiting);
            add_log(data, msg, 1);
            
            // 唤醒所有学生，即使他们没有快递
            pthread_cond_broadcast(&data->not_empty);
            
            // 如果仍然没有学生响应，强制创建空间
            if (data->parcel_count >= CABINET_SIZE) {
                // 找到最旧的快递并移除
                int oldest_slot = -1;
                struct timeval oldest_time;
                get_current_time(&oldest_time);
                
                for (int i = 0; i < CABINET_SIZE; i++) {
                    if (data->cabinet[i].parcel_id != 0) {
                        // 比较时间戳
                        if (data->cabinet[i].timestamp.tv_sec < oldest_time.tv_sec ||
                            (data->cabinet[i].timestamp.tv_sec == oldest_time.tv_sec &&
                             data->cabinet[i].timestamp.tv_usec < oldest_time.tv_usec)) {
                            oldest_slot = i;
                            oldest_time = data->cabinet[i].timestamp;
                        }
                    }
                }
                
                if (oldest_slot != -1) {
                    Parcel parcel = data->cabinet[oldest_slot];
                    data->cabinet[oldest_slot].parcel_id = 0;
                    data->parcel_count--;
                    
                    char msg[256];
                    snprintf(msg, sizeof(msg), 
                             ANSI_COLOR_RED "监控: 强制移除快递 %d (收件人: %d) 以恢复系统!" ANSI_COLOR_RESET,
                             parcel.parcel_id, parcel.student_id);
                    add_log(data, msg, 1);
                }
            }
        }
        // 恢复后退出恢复模式
        else if (data->recovery_mode && data->parcel_count < CABINET_SIZE * 0.8) {
            data->recovery_mode = 0;
            add_log(data, "监控: 系统已恢复正常运行模式", 0);
        }
        
        pthread_mutex_unlock(&data->mutex);
    }
    return NULL;
}

// 显示统计信息
void display_stats(SharedData *data) {
    // 获取终端大小
    get_terminal_size();
    int terminal_height = terminal_size.ws_row;
    int terminal_width = terminal_size.ws_col;
    
    // 计算统计区域高度（占终端高度的1/3）
    int stats_height = terminal_height / 3;
    if (stats_height < 15) stats_height = 15; // 最小高度
    
    // 移动到屏幕顶部并清除统计区域
    printf("\033[H"); // 移动光标到左上角
    printf("\033[0J"); // 清除从光标到屏幕末尾的内容
    
    // 显示系统标题
    printf(ANSI_COLOR_CYAN "===== 校园快递柜系统模拟 (毫秒级) =====\n" ANSI_COLOR_RESET);
    printf("快递柜容量: %d, 当前使用: %d, 剩余空间: %d\n", 
           CABINET_SIZE, data->parcel_count, CABINET_SIZE - data->parcel_count);
    
    // 显示快递柜使用状态
    printf("快递柜状态: [");
    int used_percent = (data->parcel_count * 100) / CABINET_SIZE;
    for (int i = 0; i < 20; i++) {
        if (i * 5 < used_percent) {
            if (used_percent >= 90) {
                printf(ANSI_COLOR_RED "#" ANSI_COLOR_RESET);
            } else if (used_percent >= 75) {
                printf(ANSI_COLOR_YELLOW "#" ANSI_COLOR_RESET);
            } else {
                printf(ANSI_COLOR_GREEN "#" ANSI_COLOR_RESET);
            }
        } else {
            printf("-");
        }
    }
    printf("] %d%%", used_percent);
    
    // 特殊状态显示
    if (data->parcel_count >= CABINET_SIZE) {
        printf(ANSI_COLOR_RED " 爆仓!" ANSI_COLOR_RESET);
    }
    if (data->recovery_mode) {
        printf(ANSI_COLOR_RED " 恢复模式!" ANSI_COLOR_RESET);
    }
    printf("\n");
    
    // 等待线程统计
    printf("等待快递员: %d, 等待学生: %d\n", 
           data->couriers_waiting, data->students_waiting);
    
    // 显示吞吐量统计
    printf("\n" ANSI_COLOR_CYAN "===== 实时吞吐量统计 =====\n" ANSI_COLOR_RESET);
    printf("投递速率: %.2f 件/分钟\n", data->stats.in_rate);
    printf("取件速率: %.2f 件/分钟\n", data->stats.out_rate);
    printf("总投递量: %ld, 总取件量: %ld\n", 
           data->stats.total_delivered, data->stats.total_picked);
    
    // 显示快递员工作效率统计
    printf("\n" ANSI_COLOR_CYAN "===== 快递员工作效率 =====\n" ANSI_COLOR_RESET);
    for (int i = 0; i < NUM_COURIERS; i++) {
        int min = courier_efficiency[i][0];
        int max = courier_efficiency[i][1];
        double rate = 60000.0 / ((min + max) / 2.0); // 每分钟投递次数
        
        // 计算平均实际等待时间
        double avg_wait = 0.0;
        if (data->stats.delivery_count > 0) {
            avg_wait = data->stats.total_delivery_time / 1000.0 / data->stats.delivery_count;
        }
        
        printf("快递员 %d: %d-%d毫秒/件 (%.1f件/分), 已投递: %ld件, 平均等待: %.2f毫秒\n", 
               i, min, max, rate, data->stats.courier_stats[i], avg_wait);
    }
    
    // 显示学生取件统计
    printf("\n" ANSI_COLOR_CYAN "===== 学生取件统计 =====\n" ANSI_COLOR_RESET);
    printf("学生数量: %d, 取件间隔: %d-%d秒\n", 
           NUM_STUDENTS, STUDENT_MIN_SLEEP, STUDENT_MAX_SLEEP);
    
    // 显示分隔线
    printf("\n" ANSI_COLOR_MAGENTA);
    for (int i = 0; i < terminal_width; i++) printf("=");
    printf(ANSI_COLOR_RESET);
    
    fflush(stdout); // 立即刷新输出
}

// 显示日志
void display_logs(SharedData *data) {
    pthread_mutex_lock(&data->log_mutex);
    
    // 获取终端大小
    get_terminal_size();
    int terminal_height = terminal_size.ws_row;
    int terminal_width = terminal_size.ws_col;
    
    // 计算日志区域高度（终端高度减去统计区域高度）
    int stats_height = terminal_height / 3;
    if (stats_height < 15) stats_height = 15;
    int log_height = terminal_height - stats_height - 1; // 减去分隔线
    
    // 移动到日志区域
    printf("\033[%d;0H", stats_height + 1); // 移动到统计区域下方
    
    // 只显示最新的日志（最多log_height条）
    int start_index = data->log_count > log_height ? data->log_count - log_height : 0;
    int lines_to_display = data->log_count - start_index;
    
    if (lines_to_display > log_height) {
        start_index = data->log_count - log_height;
        lines_to_display = log_height;
    }
    
    // 清除日志区域
    printf("\033[0J"); // 清除从光标到屏幕末尾的内容
    
    // 显示日志标题
    printf(ANSI_COLOR_BLUE "===== 系统日志 (最新%d条) =====\n" ANSI_COLOR_RESET, lines_to_display);
    
    // 显示日志
    for (int i = start_index; i < data->log_count; i++) {
        LogEntry entry = data->log_queue[i];
        char time_buf[64];
        struct tm *tm_info = localtime(&entry.timestamp.tv_sec);
        strftime(time_buf, sizeof(time_buf), "%H:%M:%S", tm_info);
        int ms = entry.timestamp.tv_usec / 1000;
        
        if (entry.is_warning) {
            printf(ANSI_COLOR_YELLOW "[%s.%03d] %s\n" ANSI_COLOR_RESET, time_buf, ms, entry.message);
        } else {
            printf("[%s.%03d] %s\n", time_buf, ms, entry.message);
        }
    }
    
    pthread_mutex_unlock(&data->log_mutex);
    fflush(stdout);
}

// 日志线程函数
void *logger_thread(void *arg) {
    SharedData *data = (SharedData *)arg;
    struct timeval last_stat_display;
    get_current_time(&last_stat_display);
    
    // 清屏并初始化显示
    printf("\033[2J\033[H"); // 清屏
    display_stats(data);
    display_logs(data);
    
    while (1) {
        // 定期更新统计信息和日志
        struct timeval now;
        get_current_time(&now);
        
        // 计算时间差(秒)
        double elapsed = (now.tv_sec - last_stat_display.tv_sec) +
                        (now.tv_usec - last_stat_display.tv_usec) / 1000000.0;
        
        if (elapsed >= 1.0) { // 每秒更新一次
            display_stats(data);
            display_logs(data);
            last_stat_display = now;
        }
        
        // 短暂睡眠避免忙等待
        usleep(100000); // 100ms
    }
    return NULL;
}

int main() {
    srand(time(NULL)); // 初始化随机种子
    
    // 获取终端大小
    get_terminal_size();
    
    printf("===== 校园快递柜系统模拟 (毫秒级) =====\n");
    printf("快递员数量: %d\n", NUM_COURIERS);
    printf("学生数量: %d\n", NUM_STUDENTS);
    printf("快递柜容量: %d\n", CABINET_SIZE);
    printf("快递员投递间隔: 毫秒级\n");
    printf("学生取件间隔: %d-%d秒\n", STUDENT_MIN_SLEEP, STUDENT_MAX_SLEEP);
    printf("============================\n");
    printf("按Ctrl+C退出程序\n\n");
    
    // 显示快递员效率配置
    printf("快递员效率配置:\n");
    for (int i = 0; i < NUM_COURIERS; i++) {
        printf("  快递员 %d: %d-%d毫秒/件\n", i, 
               courier_efficiency[i][0], courier_efficiency[i][1]);
    }
    printf("\n系统将在3秒后启动...\n");
    sleep(3);
    
    SharedData shared_data;
    init_shared_data(&shared_data);
    
    pthread_t couriers[NUM_COURIERS];
    pthread_t students[NUM_STUDENTS];
    pthread_t logger;
    pthread_t monitor;
    
    // 创建快递员线程
    for (int i = 0; i < NUM_COURIERS; i++) {
        // 准备参数 (共享数据指针 + 快递员ID)
        void **params = malloc(2 * sizeof(void *));
        params[0] = &shared_data;
        params[1] = (void *)(long)i;
        
        if (pthread_create(&couriers[i], NULL, courier_thread, params) != 0) {
            perror("创建快递员线程失败");
            exit(EXIT_FAILURE);
        }
    }
    
    // 创建学生线程
    for (int i = 0; i < NUM_STUDENTS; i++) {
        // 准备参数 (共享数据指针 + 学生ID)
        void **params = malloc(2 * sizeof(void *));
        params[0] = &shared_data;
        params[1] = (void *)(long)(i + 1); // 学生ID从1开始
        
        if (pthread_create(&students[i], NULL, student_thread, params) != 0) {
            perror("创建学生线程失败");
            exit(EXIT_FAILURE);
        }
    }
    
    // 创建监控线程
    if (pthread_create(&monitor, NULL, monitor_thread, &shared_data) != 0) {
        perror("创建监控线程失败");
        exit(EXIT_FAILURE);
    }
    
    // 创建日志线程
    if (pthread_create(&logger, NULL, logger_thread, &shared_data) != 0) {
        perror("创建日志线程失败");
        exit(EXIT_FAILURE);
    }
    
    // 等待所有线程（实际上永远不会结束）
    pthread_join(logger, NULL);
    pthread_join(monitor, NULL);
    for (int i = 0; i < NUM_COURIERS; i++) {
        pthread_join(couriers[i], NULL);
    }
    for (int i = 0; i < NUM_STUDENTS; i++) {
        pthread_join(students[i], NULL);
    }
    
    return 0;
}