/**********************************

本题要求编写程序，对一个以“#”结束的字符串，
将其小写字母全部转换成大写字母，把大写字母全部转换成小写字母，其他字符不变输出。

输入格式：
输入为一个以“#”结束的字符串（不超过30个字符）。

输出格式：
在一行中输出大小写转换后的结果字符串。

输入样例：
Hello World! 123#

输出样例：
hELLO wORLD! 123

***********************************/

#include <stdio.h>

int main() {
    char str[31];

    fgets(str, 31, stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            str[i] = '\0';
            break;
        }
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }

    printf("%s\n", str);
    return 0;
}