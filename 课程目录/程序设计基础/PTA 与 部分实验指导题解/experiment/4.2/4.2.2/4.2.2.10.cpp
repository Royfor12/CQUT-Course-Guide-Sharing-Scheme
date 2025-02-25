#include <stdio.h>

int main() {
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

    return 0;
}