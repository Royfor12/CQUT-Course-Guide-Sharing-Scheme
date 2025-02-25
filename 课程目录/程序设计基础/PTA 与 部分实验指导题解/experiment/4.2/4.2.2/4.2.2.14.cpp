#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;

    printf("输入第一条直角边的长度：");
    scanf("%f", &a);
    printf("输入第二条直角边的长度：");
    scanf("%f", &b);

    c = sqrt(a * a + b * b);

    printf("斜边长为: %.2f\n", c);

return 0;
}