/**********************************

从键盘输入一个字符串给str和一个字符c，删除str中的所有字符c并输出删除后的字符串str。

输入格式:
第一行是一个字符串，不超过100个字符 ，可以带空格；
第二行是一个字符。

输出格式:
删除指定字符后的字符串。

输入样例:
在这里给出一组输入。例如：
sdf$$$sdf$$
$

输出样例:
在这里给出相应的输出。例如：
sdfsdf

***********************************/

#include <stdio.h>
#include <string.h>
int main() {
    char str[101];
    char c;
    gets(str);
    scanf("%c", &c);
    for(int i = 0; i < strlen(str); i++) {
        if(str[i]!= c) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}