/**********************************

编写程序：从键盘任意输入三个整数，计算并输出它们的平均值，以及这三个整数的乘积。平均值的小数点后面保留2位输出。

输入格式:
输入：在一行中输入3个绝对值不超过1000的非0整数。

输出格式:
对每一组输入，在一行中输出3个整数的平均值，和3个整数的乘积，其间用一个空格分开。

输入样例:
例如：
4 5 7

输出样例:
在这里给出相应的输出。例如：
5.33 140

**********************************/

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    double average = (a + b + c) / 3.0;
    int plus = a * b * c;

    printf("%.2f %d", average, plus);

    return 0;
}
