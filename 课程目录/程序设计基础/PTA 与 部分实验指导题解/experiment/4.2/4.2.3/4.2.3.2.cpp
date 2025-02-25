#include <stdio.h>
#include <math.h>

int main() {
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

return 0;
}