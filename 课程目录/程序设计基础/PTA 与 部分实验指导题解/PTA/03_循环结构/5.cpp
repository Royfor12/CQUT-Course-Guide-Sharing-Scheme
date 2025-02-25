/**********************************

一个正整数 N 的因子中可能存在若干连续的数字。例如 630 可以分解为 3×5×6×7，其中 5、6、7 就是 3 个连续的数字。给定任一正整数 N，要求编写程序求出最长连续因子的个数，并输出最小的连续因子序列。

输入格式：
输入在一行中给出一个正整数 N（1<N<2^31）。

输出格式：
首先在第 1 行输出最长连续因子的个数；然后在第 2 行中按 因子1*因子2*……*因子k 的格式输出最小的连续因子序列，其中因子按递增顺序输出，1 不算在内。

输入样例：
630

输出样例：
3
5*6*7

***********************************/

#include <stdio.h>
#include <math.h>

int main(void) {
    int N = 0;
    scanf("%d", &N);

    int max_factor_length = 0, count = 0, the_smallest_factor = 0;
    for (int i = 2; i <= (int)sqrt(N); i++) {
        if (N % i == 0) {
            count++;
            int temp = N / i;  //temp是配对因子
            for (int j = i + 1; j <= (int)sqrt(N) + 1; j++) {
                if (temp % j == 0) {  //配对因子j
                    temp /= j;
                    count++;
                    //更新最大长度和最小因子
                    if (count > max_factor_length) {
                        max_factor_length = count;
                        the_smallest_factor = j - max_factor_length + 1;
                    }
                } else {  //配对因子j不连续，重置count
                    if (count > max_factor_length) {
                        max_factor_length = count;
                        the_smallest_factor = j - max_factor_length;
                    }
                    count = 0;
                    break;  //break出for循环，进入下一个i
                }
            }
        }
    }

    if (max_factor_length == 0) {  //质数
        printf("1\n%d", N);
    } else {
        printf("%d\n", max_factor_length);
        //最小因子序列
        for (int i = the_smallest_factor; i < the_smallest_factor + max_factor_length - 1; i++) {
            printf("%d*", i);
        }
        //最后一个因子单独输出，避免多余*
        printf("%d", the_smallest_factor + max_factor_length - 1);
    }
}