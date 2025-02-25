/**********************************

判断一个5位数是不是回文数。例如12321是一个回文数，即它的个位与万位相同，十位与千位相同。。

输入格式:
直接输入一个5位数正整数。

输出格式:
输出“yes”或“no”。此处均为小写字母

输入样例:
12521

输出样例:
yes

输入样例:
65432

输出样例:
no

***********************************/

#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    int wan = num / 10000;
    int qian = (num / 1000) % 10;
    int bai = (num / 100) % 10;
    int shi = (num / 10) % 10;
    int ge = num % 10;

    if (wan == ge && qian == shi) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

return 0;
}