#include <stdio.h>

int main() {
    char a, b, c, max;
    printf("请输入三个字符：");
    scanf("%c %c %c", &a, &b, &c);

    if (a > b && a > c) {
        max = a;
    } else if (b > a && b > c) {
        max = b;
    } else {
        max = c;
    }

    printf("最大的字符是：%c\n", max);
    
return 0;
}
