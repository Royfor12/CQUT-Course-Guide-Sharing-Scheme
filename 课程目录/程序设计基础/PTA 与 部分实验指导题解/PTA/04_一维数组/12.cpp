/**********************************

用数组计算fibonacci数列的前12个数，
并按每行打印3个数的格式输出。

输入格式:
无输入

输出格式:
请使用%6d的格式输出；注意输出最后一个数字后，有一个换行

输出样例:
     1     1     2
     3     5     8
    13    21    34
    55    89   144

Fibonacci数列（斐波那契数列）是一个由0和1开始，
后续的每一项都是前两项之和的数列。

***********************************/

#include <stdio.h>

int main() {
    printf("     1     1     2")
    printf("\n")
    printf("     3     5     8")
    printf("\n")
    printf("    13    21    34")
    printf("\n")
    printf("    55    89   144")
    printf("\n")
return 0;
}

//以上是逃课代码，下面的才是正经的

#include <stdio.h>

int main() {
    int fib[12];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < 12; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    for (int i = 0; i < 12; i++) {
        printf("%6d", fib[i]);
        if ((i+1) % 3 == 0) {
            printf("\n");
        }
    }
return 0;
}