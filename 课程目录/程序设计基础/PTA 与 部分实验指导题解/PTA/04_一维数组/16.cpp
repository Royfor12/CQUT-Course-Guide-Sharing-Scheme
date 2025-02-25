/**********************************

对于输入的两个不超过100位数字的非负整数，给出两数之和。

输入格式:
在两行中分别给出两个不超过100位数字的非负整数

输出格式:
在一行中输出两数之和

输入样例:
123
12

输出样例:
135

***********************************/

//100位数字，别看成百位了，啥数据类型都不管用。

#include <stdio.h>
#define max_length 101

int main(void) {
    char num1[max_length], num2[max_length];
    int arr1[max_length] = {0}, arr2[max_length] = {0}, result[max_length] = {0};
    
    scanf("%s", num1);
    scanf("%s", num2);
    
    //获取两个数的长度
    int len1 = 0, len2 = 0;
    while (num1[len1] != '\0') len1++;
    while (num2[len2] != '\0') len2++;
    
    /*
    字符串是从左到右存储的（高位到低位），
    而程序在存储到 arr1 和 arr2 时，也是从左到右存储
    但在进行加法运算时，是按照从低位到高位（从右到左）的顺序进行的
    所以要将 num1 和 num2 反向存入数组（从低位到高位）
    否则样例结果为342
    */
    for (int i = 0; i < len1; i++) {
        arr1[i] = num1[len1 - 1 - i] - '0';
    }
    for (int i = 0; i < len2; i++) {
        arr2[i] = num2[len2 - 1 - i] - '0';
    }
    
    
    //获取更长数字的位数
    int max_len = (len1 > len2) ? len1 : len2;
    
    int forward = 0;  //进位的标志
    int k = 0;
    
    // 从最低位开始逐位加
    for (int m = 0; m < max_len || forward; m++) {
        int sum = arr1[m] + arr2[m] + forward;
        forward = sum / 10;
        result[k] = sum % 10;
        k++;
    }
    
    // 反向输出结果数组
    if (k == 0) {
        printf("0");
    } else {
        for (int n = k - 1; n >= 0; n--) {  //还是注意数组索引从0开始，所以n从k-1开始
            printf("%d", result[n]);
        }
    }
}




