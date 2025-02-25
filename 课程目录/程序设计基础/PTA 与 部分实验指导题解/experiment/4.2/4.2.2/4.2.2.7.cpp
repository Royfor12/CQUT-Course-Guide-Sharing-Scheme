#include <stdio.h>
int main() {

    int num1, num2, num3, sum;
    float aver;

    // 输入第一个数
    printf("输入第一个整数: ");
    while (scanf("%d", &num1) != 1) {
    printf("无效输入,在此重新输入：");
    // 清除输入
    while (getchar() != '\n');
    }

    printf("入第二个整数: ");
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

return 0;
}