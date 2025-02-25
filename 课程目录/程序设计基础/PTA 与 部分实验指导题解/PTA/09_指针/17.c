/**********************************

本题要求编写一个解密英文藏头诗的程序。建议使用动态内存分配方法处理字符串的输入。

输入格式:
输入为一首英文藏头诗，每句一行，小于20行，每行不超过80个字符，以#作为藏头诗的输入结束标志。

输出格式:
取出每句的第一个字符，连接在一起形成一个字符串并输出。

输入样例:
I come into a dream
Leaves fall down but spring
over a lake birds flying
village have its nice morning
everywhere can feel happiness
Years have never been
owners don't need anything
until the sun bring another wind
#

输出样例:
ILoveYou

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    char *str[20];
    char result[100] = "";  // 存储拼接后的结果字符串
    int lineCount = 0;

    while (1) {
        // 必须使用动态内存分配，否则过不了测试点2
        str[lineCount] = (char *)malloc(81 * sizeof(char));  // 最大80字符 + \0
        if (fgets(str[lineCount], 81, stdin) == NULL) {
            free(str[lineCount]);  // 释放内存
            break;
        }

        // 移除换行符 (原以为是这个过不了测试点2，结果不是。可以不用移除换行符，判断处改为"#\n"就行)
        if (str[lineCount][strlen(str[lineCount]) - 1] == '\n') {
            str[lineCount][strlen(str[lineCount]) - 1] = '\0';
        }

        // 判断某行是否为#\n
        if (strcmp(str[lineCount], "#") == 0) {
            break;
        }

        strncat(result, &str[lineCount][0], 1);  // stract 将第二个字符串追加到第一个字符串的末尾
        /*
        strncat 函数的语法：
            char *strncat(char *dest, const char *src, size_t n);

            dest: 目标字符串（即拼接的目标）
            src: 源字符串（即要拼接的字符串）
            n: 要从源字符串中拼接的最大字符数
        */
        lineCount++;
    }

    // 输出拼接后的字符串
    printf("%s\n", result);

    return 0;
}