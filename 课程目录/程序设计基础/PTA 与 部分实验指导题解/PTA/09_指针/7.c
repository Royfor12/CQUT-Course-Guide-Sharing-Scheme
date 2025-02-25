/**********************************

输入5个字符串，输出其中最大的字符串。

输出格式： printf("Max is: %s\n", );

输入输出示例：括号内为说明，无需输入输出

输入样例:
peach 
pear
melon
orange
berry

输出样例:
Max is: pear

***********************************/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[5][20], max[20];
    for (int i = 0; i < 5; i++)
        scanf("%s", str[i]);

    strcpy(max, str[0]);  // 初始化max
    for (int i = 1; i < 5; i++)
        if (strcmp(str[i], max) > 0)
            strcpy(max, str[i]);
    printf("Max is: %s\n", max);
    return 0;
}