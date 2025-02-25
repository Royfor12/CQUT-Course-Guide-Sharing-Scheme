/**********************************

1个数的因子(此处因子不包括自己)和等于其自身的数被称为完数：
如6=1+2+3，28=1+2+4+7+14，则6、28都是完数。

输入格式:
输入两个数n和m(n<m<20000)。

输出格式:
输出[n, m]间的所有完数。

输入样例:
1 100

输出样例:
6 28 

***********************************/

#include <stdio.h>

int iffunction(int n) {
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return (n == sum) ? 1 : 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int j = n; j <= m; j++) {
        if (j > 1 && iffunction(j) != 0) {
            printf("%d ", j);
        }
    }
    return 0;
}



