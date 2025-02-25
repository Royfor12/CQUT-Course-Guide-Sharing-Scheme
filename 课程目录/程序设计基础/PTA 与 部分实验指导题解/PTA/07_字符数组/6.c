/**********************************

输入一串由字母和数字组成的字符，将数字选出，求和。

输入格式:
输入一串有数字和英文字母组成的字符，回车结束

输出格式:
将数字字符选出，转换成整数求和

输入样例:
a1b2c3d4e5f

输出样例:
15

***********************************/

#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    scanf("%s", str);
    int sum = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            sum += str[i] - '0';
        }
    }
    printf("%d", sum);
    return 0;
}


