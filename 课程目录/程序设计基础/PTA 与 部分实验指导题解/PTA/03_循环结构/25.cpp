/**********************************

现在常见的哥德巴赫猜想陈述为欧拉的版本，即任一大于2的偶数都可写成两个素数之和。
请编写程序，读入2个整数m和n，然后输出m到n之间所有偶数的一组分解结果。

输入格式:
输入在一行中给出2个绝对值不超过10000的整数m和n（4<=m<=n<=10000）。

输出格式:
每行一个偶数分解结果，按照格式“x=p+q”形式输出x的素数分解（m<=x<=n），
其中p、q均为素数，p<=q，同时要求对于每一个偶数必须输出所有解中p最小的解。

输入样例:
6 12

输出样例:
6=3+3
8=3+5
10=3+7
12=5+7

***********************************/

#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        if (i % 2 == 0) {
            for (int j = 2; j <= i / 2; j++) {
                if (isPrime(j) && isPrime(i - j)) {
                    printf("%d=%d+%d\n", i, j, i - j);
                    break;
                }
            }
        }
    }

return 0;
}
