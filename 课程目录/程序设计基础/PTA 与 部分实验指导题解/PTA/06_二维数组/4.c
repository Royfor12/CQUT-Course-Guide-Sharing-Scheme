/**********************************

实验五：数组

实验目的：

掌握一维数组和二维数组的定义、赋值和输入输出的方法。
掌握字符数组和字符串函数的使用。
题目描述

对三个字符串按由小到大的顺序排序。（定义二维字符数组）

输入格式:
输入三个字符串。（字符最大长度30）

输出格式:
按由小到大的顺序输出三个字符串。

输入样例:
在这里给出一组输入。例如：
Japan
China
German

输出样例:
在这里给出相应的输出。例如：
China
German
Japan

***********************************/

#include <stdio.h>

int compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }

    // 如果循环结束，说明两个字符串在前面部分相同，则比较长度
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    }
    // 短的排在前面
    if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

// 交换str1和str2
void swap(char str1[], char str2[]) {
    char temp[31];
    int i = 0;
    
    // 将str1复制到temp中
    while (str1[i] != '\0') {
        temp[i] = str1[i];
        i++;
    }
    temp[i] = '\0';  // 为字符串添加结束符，不然就变成数组了

    // 将str2复制到str1
    i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    
    // 将temp复制到str2
    i = 0;
    while (temp[i] != '\0') {
        str2[i] = temp[i];
        i++;
    }
    str2[i] = '\0';
}

int main(void) {
    char string[3][31];  // 存储3个字符串，最多30个字符 + 1个'\0'

    for (int i = 0; i < 3; i++) 
    {
        scanf("%31s", string[i]);  // %s:表示读取一个字符串，直到遇到空白字符（空格、制表符或换行符）为止
    }

    // 冒泡排序
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (compare(string[i], string[j]) > 0) 
            {
                swap(string[i], string[j]);
            }
        }
    }

    for (int i = 0; i < 3; i++) 
    {
        printf("%s\n", string[i]);
    }

    return 0;
}


