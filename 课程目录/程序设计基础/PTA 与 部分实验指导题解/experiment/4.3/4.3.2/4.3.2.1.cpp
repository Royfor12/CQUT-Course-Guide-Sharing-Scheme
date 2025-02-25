#include <stdio.h>

int main() {
    int a, b, c, max;
    printf("请输入三个整数：");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }

    printf("最大的整数是：%d\n", max);
    
return 0;
}
