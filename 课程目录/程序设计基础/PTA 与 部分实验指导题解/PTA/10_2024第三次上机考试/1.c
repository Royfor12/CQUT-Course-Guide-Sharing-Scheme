/**********************************

以指针的方式，将某个字符串中出现的特定字符删去，然后输出新的字符串。

输入格式:
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。
每组测试数据输入一个字符串s和一个非空格字符t。其中s的长度不超过100，且只包含英文字母。

输出格式:
对于每组测试，将删掉t后新得到的字串输出。如果串被删空，则输出NULL。

输入样例:
2
eeidliecielpvu i
ecdssnepffnofdoenci e
输出样例:
eedlecelpvu
cdssnpffnofdonci

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    int  T;
    scanf("%d", &T);

    while (T--) {
        char s[1001], t;
        scanf("%s %c", s, &t);

        char* write = s, * read = s;
        while (*read) {
            if (*read != t) {
                *write = *read;
                write++;
            } read++;
        }
        *write = '\0';

        if (write == s) {
            printf("NULL\n");
        }
        else {
            printf("%s\n", s);
        }
    }
    return 0;
}