/**********************************

本题目要求读入2个正整数x和k，然后输出大于等于x的k个最小素数。

输入格式:
输入2个正整数x（1-10000）和k（1-50）

输出格式:
输出k个素数，从小到大排列，每一行5个数据，每个数据间用一个空格隔开，最后也有一个空格。

输入样例:
4 6
输出样例:
5 7 11 13 17 
19 

***********************************/

#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    if (num == 1)
    return 0;

return 1;
}

int main() {
    int x, k;
    scanf("%d %d", &x, &k);
    int count = 0;
    
    for (int num = x; count < k; num++) {
        if (isPrime(num) == 1) {
            printf("%d ", num);
            count++;
            if (count % 5 == 0)
            printf("\n");  //用数组好像无法实现每五个换行
        }
    }

return 0;
}
