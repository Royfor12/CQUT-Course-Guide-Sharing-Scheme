/**********************************

本题要求编写程序，使用指针方式实现两个字符串的连接
(不能使用strcat函数），并将连接后的字符串输出。

输入格式:
输入一行以回车结束的非空字符串（不超过40个字符），再输入一行以回车结束的非空字符串（不超过40个字符）。

输出格式:
一行输出俩字符串连接后新的字符串。

输入样例:
Beijing_
China

输出样例:
Beijing_China

***********************************/

#include<stdio.h>
#include<string.h>

int main() {
    char *str1 = (char *)malloc(40);
    char *str2 = (char *)malloc(40);
    gets(str1);
    gets(str2);
    char *p = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    for (int i = 0; i < strlen(str1); i++)
    {
        *(p + i) = *(str1 + i);
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        *(p + strlen(str1) + i) = *(str2 + i);
    }
    *(p + strlen(str1) + strlen(str2)) = '\0';
    puts(p);
    free(p); free(str1); free(str2);
    return 0;
}