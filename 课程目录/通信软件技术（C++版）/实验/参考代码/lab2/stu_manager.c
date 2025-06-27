#include "stu_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int studentCount = 0;
static Student students[MAX_STUDENTS];

void stuManagerMain() {
    loadStudents();
    
    int choice;
    do {
        printf("\n教学管理系统\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生\n");
        printf("4. 查找学生\n");
        printf("5. 显示所有学生\n");
        printf("6. 按总成绩排序\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        __attribute__((unused)) int ret = scanf("%d", &choice);
        clearInputBuffer();  // 清除输入缓冲区
        
        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: modifyStudent(); break;
            case 4: searchStudent(); break;
            case 5: displayAllStudents(); break;
            case 6: sortStudents(); break;
            case 0: saveStudents(); break;
            default: printf("无效选择，请重新输入!\n");
        }
    } while (choice != 0);
}

// 计算总成绩
void calculateTotalScore(Student *s) {
    s->total_score = s->math_score + s->english_score + s->political_score;
}

// 加载学生数据
void loadStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("数据文件不存在，将创建新文件.\n");
        return;
    }
    
    studentCount = 0;
    while (1) {
        char gender[2];
        __attribute__((unused)) int ret = fscanf(file, "%19[^,],%49[^,],%1[^,],%49[^,],%19[^,],%f,%f,%f,%f\n", 
                  students[studentCount].id, 
                  students[studentCount].name,
                  gender,
                  students[studentCount].major,
                  students[studentCount].class_name,
                  &students[studentCount].math_score,
                  &students[studentCount].english_score,
                  &students[studentCount].political_score,
                  &students[studentCount].total_score);
        if (feof(file)) break;
        
        students[studentCount].gender = gender[0];
        studentCount++;
        if (studentCount >= MAX_STUDENTS) break;
    }
    
    fclose(file);
    printf("已加载 %d 名学生数据.\n", studentCount);
}

// 保存学生数据
void saveStudents() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("无法保存数据!\n");
        return;
    }
    
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s,%s,%c,%s,%s,%.1f,%.1f,%.1f,%.1f\n", 
                students[i].id, 
                students[i].name,
                students[i].gender,
                students[i].major,
                students[i].class_name,
                students[i].math_score,
                students[i].english_score,
                students[i].political_score,
                students[i].total_score);
    }
    
    fclose(file);
    printf("数据已保存到 %s.\n", FILENAME);
}

// 添加学生
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("学生数量已达上限!\n");
        return;
    }
    
    Student newStudent;
    
    printf("输入学号: ");
    __attribute__((unused)) char* ret1 = fgets(newStudent.id, sizeof(newStudent.id), stdin);
    newStudent.id[strcspn(newStudent.id, "\n")] = '\0';  // 移除换行符
    
    // 检查学号是否重复
    if (findStudentIndex(newStudent.id) != -1) {
        printf("学号已存在!\n");
        return;
    }
    
    printf("输入姓名: ");
    __attribute__((unused)) char* ret2 = fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    
    // 输入性别
    while (1) {
        printf("输入性别 (M/F): ");
        __attribute__((unused)) int ret3 = scanf(" %c", &newStudent.gender);
        clearInputBuffer();
        
        newStudent.gender = toupper(newStudent.gender);
        if (newStudent.gender == 'M' || newStudent.gender == 'F') {
            break;
        }
        printf("无效的性别输入，请重新输入 (M 或 F)!\n");
    }
    
    printf("输入专业: ");
    __attribute__((unused)) char* ret4 = fgets(newStudent.major, sizeof(newStudent.major), stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = '\0';
    
    printf("输入班级: ");
    __attribute__((unused)) char* ret5 = fgets(newStudent.class_name, sizeof(newStudent.class_name), stdin);
    newStudent.class_name[strcspn(newStudent.class_name, "\n")] = '\0';
    
    printf("输入高数成绩: ");
    __attribute__((unused)) int ret6 = scanf("%f", &newStudent.math_score);
    
    printf("输入英语成绩: ");
    __attribute__((unused)) int ret7 = scanf("%f", &newStudent.english_score);
    
    printf("输入思政成绩: ");
    __attribute__((unused)) int ret8 = scanf("%f", &newStudent.political_score);
    
    clearInputBuffer();  // 清除输入缓冲区
    
    // 计算总成绩
    calculateTotalScore(&newStudent);
    
    students[studentCount] = newStudent;
    studentCount++;
    saveStudents();
    printf("学生添加成功!\n");
}

// 删除学生
void deleteStudent() {
    char id[20];
    printf("输入要删除的学生学号: ");
    __attribute__((unused)) char* ret = fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int index = findStudentIndex(id);
    if (index == -1) {
        printf("未找到该学生!\n");
        return;
    }
    
    for (int i = index; i < studentCount - 1; i++) {
        students[i] = students[i + 1];
    }
    
    studentCount--;
    saveStudents();
    printf("学生删除成功!\n");
}

// 修改学生信息
void modifyStudent() {
    char id[20];
    printf("输入要修改的学生学号: ");
    __attribute__((unused)) char* ret = fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int index = findStudentIndex(id);
    if (index == -1) {
        printf("未找到该学生!\n");
        return;
    }
    
    printf("修改学生信息 (留空则保持不变):\n");
    
    char input[100];
    float newScore;
    int modified = 0;
    
    // 修改姓名
    printf("新姓名 (当前: %s): ", students[index].name);
    __attribute__((unused)) char* ret1 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(students[index].name, input);
        modified = 1;
    }
    
    // 修改性别
    char newGender;
    printf("新性别 (当前: %c) (M/F, 留空保持不变): ", students[index].gender);
    __attribute__((unused)) char* ret2 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        newGender = toupper(input[0]);
        if (newGender == 'M' || newGender == 'F') {
            students[index].gender = newGender;
            modified = 1;
        } else {
            printf("无效的性别输入，保持原值不变.\n");
        }
    }
    
    // 修改专业
    printf("新专业 (当前: %s): ", students[index].major);
    __attribute__((unused)) char* ret3 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(students[index].major, input);
        modified = 1;
    }
    
    // 修改班级
    printf("新班级 (当前: %s): ", students[index].class_name);
    __attribute__((unused)) char* ret4 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        input[strcspn(input, "\n")] = '\0';
        strcpy(students[index].class_name, input);
        modified = 1;
    }
    
    // 修改高数成绩
    printf("新高数成绩 (当前: %.1f): ", students[index].math_score);
    __attribute__((unused)) char* ret5 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        __attribute__((unused)) int ret = sscanf(input, "%f", &newScore);
        students[index].math_score = newScore;
        modified = 1;
    }
    
    // 修改英语成绩
    printf("新英语成绩 (当前: %.1f): ", students[index].english_score);
    __attribute__((unused)) char* ret6 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        __attribute__((unused)) int ret = sscanf(input, "%f", &newScore);
        students[index].english_score = newScore;
        modified = 1;
    }
    
    // 修改思政成绩
    printf("新思政成绩 (当前: %.1f): ", students[index].political_score);
    __attribute__((unused)) char* ret7 = fgets(input, sizeof(input), stdin);
    if (input[0] != '\n') {
        __attribute__((unused)) int ret = sscanf(input, "%f", &newScore);
        students[index].political_score = newScore;
        modified = 1;
    }
    
    // 如果有修改，重新计算总成绩并保存
    if (modified) {
        calculateTotalScore(&students[index]);
        saveStudents();
        printf("学生信息修改成功!\n");
    } else {
        printf("未作任何修改.\n");
    }
}

// 查找学生
void searchStudent() {
    char id[20];
    printf("输入要查找的学生学号: ");
    __attribute__((unused)) char* ret = fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';
    
    int index = findStudentIndex(id);
    if (index == -1) {
        printf("未找到该学生!\n");
        return;
    }
    
    printf("\n学生详细信息:\n");
    printf("====================================================\n");
    displayStudentDetails(students[index]);
    printf("====================================================\n");
}

// 显示所有学生
void displayAllStudents() {
    if (studentCount == 0) {
        printf("没有学生记录!\n");
        return;
    }
    
    printf("\n所有学生信息 (%d 名):\n", studentCount);
    printf("========================================================================================================\n");
    printf("学号      | 姓名         | 性别 | 专业              | 班级    | 高数   | 英语   | 思政   | 总成绩   |\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s| %-13s| %-5c| %-18s| %-8s| %-7.1f| %-7.1f| %-7.1f| %-9.1f|\n", 
               students[i].id, 
               students[i].name,
               students[i].gender,
               students[i].major,
               students[i].class_name,
               students[i].math_score,
               students[i].english_score,
               students[i].political_score,
               students[i].total_score);
    }
    printf("========================================================================================================\n");
}

static int compare(const void* a, const void* b)
{
    return (((const Student*)b)->total_score - ((const Student*)a)->total_score);
}

// 按总成绩排序
void sortStudents() {
    if (studentCount == 0) {
        printf("没有学生记录!\n");
        return;
    }
    
    // 创建副本进行排序
    Student sorted[MAX_STUDENTS];
    memcpy(sorted, students, sizeof(Student) * studentCount);
    
    // 使用冒泡排序按总成绩降序排列
    // for (int i = 0; i < studentCount - 1; i++) {
    //     for (int j = 0; j < studentCount - i - 1; j++) {
    //         if (sorted[j].total_score < sorted[j + 1].total_score) {
    //             Student temp = sorted[j];
    //             sorted[j] = sorted[j + 1];
    //             sorted[j + 1] = temp;
    //         }
    //     }
    // }

    // 改用快速排序
    qsort(sorted, studentCount, sizeof(Student), compare);

    printf("\n按总成绩排序结果 (从高到低):\n");
    printf("========================================================================================================\n");
    printf("学号      | 姓名         | 性别 | 专业              | 班级    | 高数   | 英语   | 思政   | 总成绩   |\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s| %-13s| %-5c| %-18s| %-8s| %-7.1f| %-7.1f| %-7.1f| %-9.1f|\n", 
               sorted[i].id, 
               sorted[i].name,
               sorted[i].gender,
               sorted[i].major,
               sorted[i].class_name,
               sorted[i].math_score,
               sorted[i].english_score,
               sorted[i].political_score,
               sorted[i].total_score);
    }
    printf("========================================================================================================\n");
}

// 辅助函数：查找学生索引
int findStudentIndex(const char* id) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

// 辅助函数：显示学生详细信息
void displayStudentDetails(Student s) {
    printf("学号: %s\n", s.id);
    printf("姓名: %s\n", s.name);
    printf("性别: %c\n", s.gender);
    printf("专业: %s\n", s.major);
    printf("班级: %s\n", s.class_name);
    printf("高数成绩: %.1f\n", s.math_score);
    printf("英语成绩: %.1f\n", s.english_score);
    printf("思政成绩: %.1f\n", s.political_score);
    printf("总成绩: %.1f\n", s.total_score);
}

// 清除输入缓冲区
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}