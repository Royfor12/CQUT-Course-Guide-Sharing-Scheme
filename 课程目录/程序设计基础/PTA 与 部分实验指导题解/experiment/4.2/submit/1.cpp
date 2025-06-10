#include <stdio.h>
#include <math.h>
#define PI 3.1416

void doTask(int mainTask, int subTask);

int main() {

    int mainTask, subTask, maxsubTask;

    // 开始输入项目
    while (1) {
        // 提示输入
        printf("请输入项目：\n（422 表示4.2.2，423 表示4.2.3）\n");
        scanf("%d", &mainTask);

        // 检查合法性
        if (mainTask == 422 || mainTask == 423) {
            break; // 合法输入，退出loop
        } else {
            printf("无效的项目。重新输入\n");
        }
    }

    // 项目不同，限制题号范围
    if (mainTask == 422) {
        maxsubTask = 14;
    } else if (mainTask == 423) {
        maxsubTask = 12;
    }

    // 输入小题
    while (1) {
        printf("请输入小题题号（范围：1-%d）：", maxsubTask);
        scanf("%d", &subTask);
        if (subTask >= 1 && subTask <= maxsubTask) {
            break;
        } else {
            printf("无效的小题题号！请确保在1到%d的范围内。\n", maxsubTask);
        }
    }

    // 执行相应子代码
    doTask(mainTask, subTask);

return 0;
}

// 子代码部分
void doTask(int mainTask, int subTask) {
    // 修改输出格式，直接打印 mainTask 和 subTask 的具体值
    printf("正在执行4.2.%d.%d...\n", mainTask % 10, subTask);

    if (mainTask == 422) {
        switch (subTask) {

            case 1: {
                char c1, c2;
                c1 = 97;
                c2 = 98;
                printf("c1=%c, c2=%c\n", c1, c2);
                printf("c1=%d, c2=%d\n", c1, c2);
                c1 = c1 - 32;
                c2 = c2 - 32;
                printf("c1=%c, c2=%c\n", c1, c2);
                printf("c1=%d, c2=%d\n", c1, c2);
                break;
            }

            case 2: {
                    int i, m, n;
                    i = 5;
                    printf("before i++ i=%d\n", i);
                    m = i++;
                    printf("after i++ i=%d\n", i);
                    n = ++i;
                    printf("after ++i i=%d m=%d n=%d\n", i, m, n);
            break;
            }

            case 3: {
                    int a = 3;
                    printf("%d\n", a + (a -= a * a));
            break;
            }

            case 4: {
                    int num, a = 0;
                    printf("input: ");
                    scanf("%d", &num);
                    while (num != 0) {
                        a = a * 10 + num % 10;
                        num = num / 10;
                    }
                    printf("result is: %d\n", a);
            break;
            }

            case 5: {
                    int a, n;
                    a = 12, n = 5;
                    printf("%d\n", a += a);
                    printf("%d\n", a -= 2);
                    printf("%d\n", a *= 2 + 3);
                    printf("%d\n", a %= (n %= 2));
                    printf("%d\n", a /= a + a);
                    printf("%d\n", a + a - a * a);
            break;
            }

            case 6: {
                int a, b, x, y;
                a = 2.0, b = 3.0, x = 3.5, y = 2.5;
                printf("result 1 = %f\n", ((float)(a + b)) / 2.0 + (int)x % (int)y);
                printf("result 2 = %f\n", (float)(a + b / 2.0) + (int)x % (int)y);
                printf("result 3 = %f\n", (float)(a + b / 2.0) + (int)x % (int)y);
            break;
            }

            case 7: {
                    int num1, num2, num3, sum;
                    float aver;
                    printf("输入第一个整数: ");
                    while (scanf("%d", &num1) != 1) {
                        printf("无效输入,在此重新输入：");
                        while (getchar() != '\n');
                    }
                    printf("输入第二个整数: ");
                    while (scanf("%d", &num2) != 1) {
                        printf("无效输入,在此重新输入：");
                        while (getchar() != '\n');
                    }
                    printf("输入第三个整数: ");
                    while (scanf("%d", &num3) != 1) {
                        printf("无效输入,在此重新输入：");
                        while (getchar() != '\n');
                    }
                    sum = num1 + num2 + num3;
                    aver = (float)sum / 3;
                    printf("三个数的和为: %d\n", sum);
                    printf("三个数的平均值为: %.2f\n", aver);
            break;
            }

            case 8:  {
                    int ASCII_Value, a;
                    while (1) {
                        printf("请输入一个ASCII码值（0-127）：");
                        a = scanf("%d", &ASCII_Value);
                        if (a == 1 && ASCII_Value >= 0 && ASCII_Value <= 127) {
                            printf("对应的字符是: %c\n", ASCII_Value);
                        } else {
                            while (getchar() != '\n');
                            printf("请输入有效的ASCII码值（0-127）。\n");
                        }
                    }
            }

            case 9: {
                int a, b, c;
                printf("input three integers:");
                scanf("%d %d %d", &a, &b, &c);
                int result = a * 100 + b * 10 + c;
                printf("result is: %d\n", result);
            break;
            }

            case 10: {
                    char CapsLock;
                    int result;
                    while (1) {
                        // 提示输入一个大写字母
                        printf("请输入一个大写字母：");
                        result = scanf(" %c", &CapsLock);

                        // 检查合法性
                        if (result == 1 && CapsLock >= 'A' && CapsLock <= 'Z') {
                            char disabledCapsLock = CapsLock + ('a' - 'A');
                            printf("对应的小写字母是: %c\n", disabledCapsLock);
                            break;
                        } else {
                            // 清除输入缓冲
                            while (getchar() != '\n');
                            printf("输入无效，在此重新输入：\n");
                        }
                    }
            break;
            }

            case 11: {
                    float num1, num2, temp;
                    printf("请输入第一个浮点数：");
                    scanf("%f", &num1);
                    printf("请输入第二个浮点数：");
                    scanf("%f", &num2);
                    temp = num1;
                    num1 = num2;
                    num2 = temp;
                    printf("交换后的第一个浮点数是: %.2f\n", num1);
                    printf("交换后的第二个浮点数是: %.2f\n", num2);
            break;
            }

            case 12: {
                    int year, month, day;
                    printf("请输入年份：");
                    scanf("%d", &year);
                    printf("请输入月份：");
                    scanf("%d", &month);
                    printf("请输入日期：");
                    scanf("%d", &day);
                    printf("| %d年 | %d月 | %d日 |\n", year, month, day);
            break;
            }

            case 13: {
                    float c, f;
                    printf("请输入摄氏度：");
                    scanf("%f", &c);
                    f = (c * 9 / 5) + 32;
                    printf("对应的华氏度为: %.2f\n", f);
            break;
            }
            
            case 14: {
                    float a, b, c;
                    printf("输入第一条直角边的长度：");
                    scanf("%f", &a);
                    printf("输入第二条直角边的长度：");
                    scanf("%f", &b);
                    c = sqrt(a * a + b * b);
                    printf("斜边长为: %.2f\n", c);
            break;
            }

            default: {
                    printf("无效的小题题号！\n");
            break;
            }
                
        }
    } else if (mainTask == 423) {
        switch (subTask) {

            case 1: {
                    int a ,b ,h;
                    double s;
                    a = 5, b = 10, h=6;
                    s = (a + b) * h / 2.0;
                    printf("面积为：%f\n",s);
            break;
            }

            case 2: {
                    float a, b, c;
                    float delta, x1, x2;
                    printf("请输入一元二次方程的系数a, b, c（保证有实根）：\n");
                    scanf("%f %f %f", &a, &b, &c);
                    delta = b * b - 4 * a * c;
                    if (delta > 0) {
                        x1 = (-b + sqrt(delta)) / (2 * a);
                        x2 = (-b - sqrt(delta)) / (2 * a);
                        printf("方程有两个实根：%.2f 和 %.2f\n", x1, x2);
                    } else if (delta == 0) {
                        x1 = -b / (2 * a);
                        printf("方程有一个实根：%.2f\n", x1);
                    } else {
                        printf("系数不正确，方程没有实根。\n");
                    }
            break;
            }

            case 3: {
                    char d1, d2, d3;
                    int result;
                    printf("input numbers here:");
                    scanf(" %c", &d1);
                    scanf(" %c", &d2);
                    scanf(" %c", &d3);
                    result = (d1 - '0') * 100 + (d2 - '0') * 10 + (d3 - '0');
                    printf("由输入的数字字符组成的整数是: %d\n", result);
            break;
            }

            case 4: {
                    float x, result;
                    while (1) {
                        printf("请输入一个浮点数 x (1.0 <= x <= 100.0): ");
                        scanf("%f", &x);
                        if (x >= 1.0 && x <= 100.0) {
                        break; 
                        } else {
                            while (getchar() != '\n');
                            printf("输入无效，在此重新输入：\n");
                        }
                    }
                    result = pow(x, 5);
                    printf("x 的五次方是: %.2f\n", result);
            break;
            }

            case 5: {
                    float v0 = 10.0;
                    float a = 2.0;
                    float t = 20.0;
                    float v = v0 + a * t;
                    float s = v0 * t + 0.5 * a * t * t;
                    float v_avg = s / t;
                    printf("20秒后的速度为: %.2f m/s\n", v);
                    printf("20秒内走过的路程为: %.2f m\n", s);
                    printf("20秒内的平均速度为: %.2f m/s\n", v_avg);
            break;
            }

            case 6: {
                    double mass_per_fenzi = 3e-23;
                    double mass_per_quart = 950;
                    double quarts;
                    printf("输入水的夸脱数: ");
                    scanf("%lf", &quarts);
                    double total_mass = quarts * mass_per_quart;
                    double fenzi_count = total_mass / mass_per_fenzi;
                    printf("在%.2lf夸脱的水中包含大约 %.2e 个水分子。\n", quarts, fenzi_count);
            }

            case 7: {
                    double a, b, c;
                    while (1) {  
                        printf("请输入三角形的三条边 a, b, c: ");
                        scanf("%lf %lf %lf", &a, &b, &c);
                        if (a + b > c && a + c > b && b + c > a) {
                            double s = (a + b + c) / 2;
                            double area = sqrt(s * (s - a) * (s - b) * (s - c));
                            printf("该三角形的面积为: %.2lf\n", area);
                            break;
                            } else {
                                // 判断能否构成三角形
                                while (getchar() != '\n');
                                printf("输入的三条边不能构成一个三角形。\n");
                        }
                    }
            break;
            }

            case 8: {
                    double r = 1.5;
                    double h = 3.0;
                    double circumference = 2 * PI * r;
                    double surface_area = 2 * PI * r * (r + h);
                    double volume = PI * r * r * h;
                    printf("圆柱的底面周长为: %.2lf\n", circumference);
                    printf("圆柱的表面积为: %.2lf\n", surface_area);
                    printf("圆柱的体积为: %.2lf\n", volume);
            break;
            }

            case 9: {
                    double U = 220;
                    double R1 = 10000;
                    double R2 = 10000;
                    double R3 = 200000;
                    double R4 = 200000;
                    double I1 = U / R1;
                    double I2 = U / R2;
                    double I3 = U / R3;
                    double I4 = U / R4;
                    double total_r = (1 / R1) + (1 / R2) + (1 / R3) + (1 / R4);
                    double r = 1 / total_r;
                    printf("R1 = %.6lf A\n", I1);
                    printf("R2 = %.6lf A\n", I2);
                    printf("R3 = %.6lf A\n", I3);
                    printf("R4 = %.6lf A\n", I4);
                    printf("r = %.6lf Ω\n", r);
            break;
            }

            case 10: {
                    int days;
                    printf("输入天数: ");
                    scanf("%d", &days);
                    int weeks = days / 7;
                    int remainDays = days % 7;
                    printf("%d 天等于 %d 周 %d 天\n", days, weeks, remainDays);
            break;
            }

            case 11: {
                    char input[6], output[6];
                    int choice, i = 0;
                    printf("选择操作: 1-加密, 2-解密\n");
                    scanf("%d", &choice);
                    printf("输入5位字母串: ");
                    scanf("%5s", input);
                    while (i < 5) {
                        if (choice == 1) {  // 加密
                            if (input[i] >= 'a' && input[i] <= 'z') {
                                output[i] = (input[i] - 'a' + 4) % 26 + 'a';
                            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                                output[i] = (input[i] - 'A' + 4) % 26 + 'A';
                            } else {
                                output[i] = input[i];
                            }
                        } else if (choice == 2) {  // 解密
                            if (input[i] >= 'a' && input[i] <= 'z') {
                                output[i] = (input[i] - 'a' - 4 + 26) % 26 + 'a';
                            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                                output[i] = (input[i] - 'A' - 4 + 26) % 26 + 'A';
                            } else {
                                output[i] = input[i];
                            }
                        }
                        i++;
                    }
                    if (choice == 1) {
                        printf("加密后的密码: %s\n", output);
                    } else if (choice == 2) {
                        printf("解密后的原文: %s\n", output);
                    } else {
                        printf("无效的选择\n");
                    }
            break;        
            }

            case 12: {
                    int n, square, a;
                    printf("请输入一个两位正整数: ");
                    scanf("%d", &n);
                    square = n * n;
                    a = square % 100;
                    printf("平方后构成的新整数为: %d\n", a);   
            break;            
            }
        }
    }
}