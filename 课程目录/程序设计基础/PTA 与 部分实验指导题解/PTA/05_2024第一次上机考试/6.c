/**********************************

从键盘读入不超过20个字符，统计其中大写字母、小写字母、数字、其他字符的个数。

输入格式:
在一行中输入字符

输出格式:
在一行中分别输出各种字符的个数。

输入样例1:
abcDee3

输出样例1:
在这里给出相应的输出。例如：
1,5,1,0

输入样例2:
QWQwsadffsffw21342354dsgzbfnzzzbzdfbz

输出样例2:
在这里给出相应的输出。例如：
ERROR

***********************************/

#include <stdio.h>

int main() {
    char str[21];
    fgets(str, sizeof(str), stdin);
    
    int len = 0;
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    str[len] = '\0';  // 去掉换行符

    if (len < 1 || len > 21) {
        printf("ERROR\n");
        return 0;
    }


    int upper = 0, lower = 0, digit = 0, other = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            upper++;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            lower++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            digit++;
        } else {
            other++;
        }
    }

    printf("%d,%d,%d,%d\n", upper, lower, digit, other);

    return 0;
}
