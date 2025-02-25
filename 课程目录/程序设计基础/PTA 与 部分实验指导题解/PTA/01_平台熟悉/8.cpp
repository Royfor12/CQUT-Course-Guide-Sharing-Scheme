/**********************************

任意输入一个大写字母，输出其对应的小写字母。

输入格式:
输入在一行中给出1个大写字母。

输出格式:
对每一组输入，在一行中输出小写字母。

输入样例:
在这里给出一组输入。例如：
A

输出样例:
在这里给出相应的输出。例如：
A is changed to a.

**********************************/

#include <stdio.h>

int main() {
    char uppercase;
    if (scanf("%c", &uppercase) != 1) {
        return 1;
    }
    char lowercase = uppercase + 32;
    printf("%c is changed to %c.", uppercase, lowercase);
    return 0;
}
