#include <stdio.h>

int main() {
    int ASCII_Value, a;

    while (1) {
        printf("请输入一个ASCII码值（0-127）：");
        a = scanf("%d", &ASCII_Value);

        // 检查输入是否在有效范围内
        if (a == 1 && ASCII_Value >= 0 && ASCII_Value <= 127) {
            printf("对应的字符是: %c\n", ASCII_Value);
        } else {
            while (getchar() != '\n');
            printf("请输入有效的ASCII码值（0-127）。\n");
        }
    }

return 0;
}