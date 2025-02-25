#include <stdio.h>

int main() {
    char input[6], output[6];
    int choice, i = 0;

    printf("选择操作: 1-加密, 2-解密\n");
    scanf("%d", &choice);

    printf("输入5位字母串: ");
    scanf("%5s", input);

    while (i < 5) {
        if (choice == 1) {  // 加密
            if (input[i] >= 'a' && input[i] <= 'z') {
                output[i] = (input[i] - 'a' + 4) % 26 + 'a';
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                output[i] = (input[i] - 'A' + 4) % 26 + 'A';
            } else {
                output[i] = input[i];
            }
        } else if (choice == 2) {  // 解密
            if (input[i] >= 'a' && input[i] <= 'z') {
                output[i] = (input[i] - 'a' - 4 + 26) % 26 + 'a';
            } else if (input[i] >= 'A' && input[i] <= 'Z') {
                output[i] = (input[i] - 'A' - 4 + 26) % 26 + 'A';
            } else {
                output[i] = input[i];
            }
        }
        i++;
    }

    if (choice == 1) {
        printf("加密后的密码: %s\n", output);
    } else if (choice == 2) {
        printf("解密后的原文: %s\n", output);
    } else {
        printf("无效的选择\n");
    }

return 0;
}
