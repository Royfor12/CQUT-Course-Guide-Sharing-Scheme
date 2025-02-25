/**********************************

英语老师要求学生按照如下规则写一串字母：

如果写了某个大写字母，下一个就必须写同个字母的小写，或者写字母表中下一个字母的大写；
如果写了某个小写字母，下一个就必须写同个字母的大写，或者写字母表中前一个字母的小写；
当然也可以什么都不写，就结束这个字母串。

例如 aAaABCDdcbBC 就是一个合法的字母串；而 dEFfeFGhI 就是非法的。注意 a 没有前一个字母， Z 也没有下一个字母。

现在面对全班学生交上来的作业，老师请你写个程序自动批改。

输入格式：
输入在第一行给出一个不超过 100 的正整数 N。
随后 N 行，每行给出一位学生的作业，即仅由英文字母组成的非空字母串，长度不超过 2×10^6。

输出格式：
对每位学生的作业，如果正确就在一行中输出 Y，否则输出 N。

输入样例：
2
aAaABCDdcbBC
dEFfeFGhI

输出样例：
Y
N

***********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_upper(char c) {
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    } else return 0;   
}

int is_lower(char c) {
        if (c >= 'a' && c <= 'z')
    {
        return 1;
    } else return 0;   
}

int is_valid(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len - 1; i++)
    {
        char current = s[i];
        char next = s[i + 1];

        if (is_upper(current)) {  // 如果当前是大写
            if (!(next == current + 32 ||  // 下一个是大写
            (next == current + 1 && next <= 'Z')))  // 字母表中下一个字母的大写
            {
                return 0;
            }
        } else if (is_lower(current)) {
            if (!(next == current - 32 ||  // 下一个是大写
            (next == current - 1 && next >= 'a')))  // 字母表中前一个字母的小写
            {
                return 0;  // invalid
            }
        }
    }

    return 1;
}

int main(void) {
    int N;
    scanf("%d", &N);

    char s[2000001];

    if (s == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%s", s);
        if (is_valid(s))
        {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}