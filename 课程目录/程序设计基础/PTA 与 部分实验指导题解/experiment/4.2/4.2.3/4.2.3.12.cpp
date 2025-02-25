#include <stdio.h>

int main() {
    int n, square, a;

    printf("请输入一个两位正整数: ");
    scanf("%d", &n);

    square = n * n;
    a = square % 100;

    printf("平方后构成的新整数为: %d\n", a);

return 0;
}