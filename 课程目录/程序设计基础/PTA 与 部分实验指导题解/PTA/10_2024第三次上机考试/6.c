/**********************************

用函数和指针将给定字母字符串的第一个字母变成大写字母，其它字母变成小写字母。
在main函数中接收字符串的输入，改变后的字符串的输出也在main函数中实现。

输入样例:
在这里给出一组输入。例如：

CHENGDU UNIVERSITY OF INFORMATION TECHNOLOGY 1951-2023

输出样例:
在这里给出相应的输出。例如：

Chengdu university of information technology 1951-2023

***********************************/

#include <stdio.h>

void change(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    change(s);
    s[0] = s[0] - 32;
    printf("%s", s);
    return 0;
}