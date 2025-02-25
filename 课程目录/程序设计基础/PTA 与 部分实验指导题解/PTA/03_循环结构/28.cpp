/**********************************

本题要求计算并输出不超过n的最大的k个素数以及它们的和。

输入格式:
输入在一行中给出n(10≤n≤10000)和k(1≤k≤10)的值。

输出格式:
在一行中按下列格式输出: 

素数1+素数2+…+素数k=总和值
其中素数按递减顺序输出。若n以内不够k个素数，则按实际个数输出。

输入样例1:
1000 10

输出样例1:
997+991+983+977+971+967+953+947+941+937=9664

输入样例2:
12 6

输出样例2:
11+7+5+3+2=28

***********************************/

#include <stdio.h>
#include <math.h>

int isPrime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0;
    int sum = 0;

    for (int i = n; i >= 2 && count < k; --i) {
        if (isPrime(i)) {
            sum += i;
            count++;

            if (count > 1) {
                printf("+");
            }
            printf("%d", i);
        }
    }

    printf("=%d\n", sum);

return 0;
}
