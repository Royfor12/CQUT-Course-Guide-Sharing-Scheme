/**********************************

从键盘输入一行字符，然后将其中所有的小写字母转换为对应的大写字母，
将所有的大写字母转换为对应的小写字母，
将所有的数字字符转换为ASCII代码表中的下一个字符，
其他字符保持不变。

输入格式:
一行字符。

输出格式:
变换之后的字符串，最后换行。

输入样例:
HEllo56789#$&%?

输出样例:
heLLO6789:#$&%?

***********************************/

#include<stdio.h>
#include<string.h>
int main() {
    char str[100];
    gets(str);
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
            } else if(str[i] >= '0' && str[i] <= '9') {
                str[i] = str[i] + 1;
            }
        }

    puts(str);
    return 0;
}