/**********************************

一个数如果恰好等于它的因子之和，这个数就称为“完数”。
例如：6的因子为1，2，3，而6=1+2+3，因此6是完数。输入整数n，编程找出 2~n (包括n)之内的所有完数，并按下列格式输出其因子：6 its factors are 1 2 3。

输入格式:
输入整数n(n在2-10000之间)

输出格式:
每行输出一个完数，格式如下：因子间有一个空格隔开，每行结束后也有一空格。
6 its factors are 1 2 3
......

输入样例:
10

输出样例:
6 its factors are 1 2 3 

***********************************/

#include <stdio.h>

int iffunction(int n, int factors[]) {

    int how_many_factors = 0, sum = 0;
    //计算所有因子并求和，记录有多少因子
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            factors[how_many_factors] = i;
            sum += i;
            how_many_factors++;
        }
    }
    //判断是否为完数。是完数，返回因子数量；不是，返回0。
    if (n == sum) {
        return how_many_factors;
    }
    else {
        return 0;
    }
    
}

int main() {

    int n;
    scanf("%d", &n);

    for (int j = 2; j <= n; j++) {

        int factors[1000];  //必须定义数组的大小，否则报错。

        if (iffunction(j, factors) != 0) {  //返回值不为0，是完数，输出结果
            printf("%d its factors are ", j); 
            //后面的循环输出所有因子
            for (int i = 0; i < iffunction(j, factors); i++) {
                printf("%d ", factors[i]);
            }
            printf("\n");

        }
    }

return 0;
}

