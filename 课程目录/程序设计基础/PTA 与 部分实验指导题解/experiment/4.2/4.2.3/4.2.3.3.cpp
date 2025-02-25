#include <stdio.h>

int main() {
    char d1, d2, d3;
    int result;

    printf("input numbers here:");

    scanf(" %c", &d1);
    scanf(" %c", &d2);
    scanf(" %c", &d3);

    result = (d1 - '0') * 100 + (d2 - '0') * 10 + (d3 - '0');

    printf("由输入的数字字符组成的整数是: %d\n", result);

return 0;
}