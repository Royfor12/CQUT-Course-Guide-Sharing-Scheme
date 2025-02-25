/**********************************

输入一个句子（一行），将句子中的每一个单词翻转后输出。

输入描述
只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。

输出描述
翻转每一个单词后的字符串，单词之间的空格需与原文一致。

样例输入
hello world
样例输出
olleh dlrow

样例输入
li   hai   la      wo   de      guo
样例输出
il   iah   al      ow   ed      oug

***********************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reserve(char *begin, char *end) {
    while (begin < end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++; end--;
        /*
        指针加法会按照指针的类型计算地址偏移。
        例如，对于 char* 类型，begin + 1 会移动 1 字节。
        将指针移动到下一个地址
        */
    }
}

int main() {
    char input[501];
    fgets(input, sizeof(input), stdin);

    char *begin = input;
    char *copy = input;
    while (*copy != '\0')
    {
        if (isspace(*copy))
        {
            reserve(begin, copy - 1);
            // 跳过连续的空格
            while (isspace(*copy))
            {
                copy++;
            }
            begin = copy;
        } else {
            copy++;
        }
    }

    // 修个bug，最后一个单词没有翻转，懒得重写了
    reserve(begin, copy - 1);

    printf("%s", input);

    return 0;
}

