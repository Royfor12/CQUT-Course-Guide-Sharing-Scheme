/**********************************

在m到n内找出所有的亲密数对。

若a、b为1对亲密数，则a的因子和等于b、b的因子和等于a、且a不等于b。如：220、284是1对亲密数，则284、220也是1对亲密数。（此处定义一个数的因子不包含自己，但包含1）

输入格式:
两个数m和n。

输出格式:
每行两个数a,b，表示a和b是亲密数，且a<b;每行的第一个数按从小到大输出。两个数间用一个空格隔开。

输入样例:
18 299

输出样例:
在这里给出相应的输出。例如：
220 284

***********************************/

#include <stdio.h>

int sum_of_factors(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int a = m; a <= n; a++) {
        int b = sum_of_factors(a);
        if (sum_of_factors(b) == a && a!= b && a < b) {
            printf("%d %d\n", a, b);
        }
    }
}
