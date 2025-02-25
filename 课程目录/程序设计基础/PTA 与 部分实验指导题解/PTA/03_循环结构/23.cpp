/**********************************

有n匹马要驮n担货，大马驮5担，中马驮3担，两匹小马驮1担，
问有几种驮担方案? （各种马的数量可以为0）

输入格式:
首先输入一个整数T，表示测试数据的组数，
然后是T组测试数据。每组测试数据输入一个正整数n（8≤n≤10000）。

输出格式:
对于每组测试，输出n匹马驮n担货的方案总数。

输入样例:
1
20

输出样例:
1

***********************************/

#include <stdio.h>

int solve(int n) {
    int count = 0;
    //x大马，y中马，z小马
    for(int x = 0; x <= n/5; x++) {
        for(int y = 0; y <= n/3; y++) {
            int z = n - x - y;
            if(z < 0 || z % 2 != 0) continue;  //z不是偶数,下一个循环
            if(5 * x + 3 * y + z / 2 == n) {  //总数为n
                count++;
            }
        }
    }
    return count;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
