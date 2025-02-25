#include <stdio.h>

int main() {
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

return 0;
}