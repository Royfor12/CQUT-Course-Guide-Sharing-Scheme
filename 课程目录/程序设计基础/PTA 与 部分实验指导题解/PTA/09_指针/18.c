/**********************************

从键盘任意输入一个字符串，用指针的方式计算其实际字符个数并打印出来，即不使用字符串处理函数strlen（）编程实现strlen的功能。

函数接口:
unsigned int  MyStrlen(const char *pStr)

输入格式:
字符串

输出格式:
字符串长度

输入样例:
在这里给出一组输入。例如：
hello world

输出样例:
在这里给出相应的输出。例如：
11

***********************************/

#include <stdio.h>

unsigned int MyStrlen(const char *pStr) {  
    /*char 是普通的字符类型，表示一个字符，并且该字符可以被修改。而const char 表示一个字符常量，该字符不能被修改。
    任何试图修改 const char 的操作都会导致编译错误*/
    /*unsigned int 不能表示负数，但由于不用表示符号，表示范围比int 大*/
    unsigned int count = 0;
    while (*pStr!= '\0') {
        count++;
        pStr++;
    }
    return count;
}

int main() {
    char pStr[100];
    fgets(pStr, sizeof(pStr), stdin);  // 使用 fgets, 不能用scanf, 因为scanf遇到空格就会停止读取
    printf("%u\n", MyStrlen(pStr));  // %u 用于输出unsigned int类型的值。
    return 0;
}