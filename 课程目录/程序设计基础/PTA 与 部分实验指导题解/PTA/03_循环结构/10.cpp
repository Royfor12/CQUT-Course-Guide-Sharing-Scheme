/**********************************

若一个数正向看和反向看等价，则称做回文数。例如：6，2552，12321均是回文数。

给出一个正整数n，求比n大的最小的回文数（n和运算结果均小于2^31）。

输入格式:
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试输入1个正整数n。

输出格式:
对于每组测试数据，输出比n大的最小回文数。

输入样例:
3
12
123456
111

输出样例:
22
124421
121

***********************************/

#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);
        n++;

        while (1) {
            int original = n, turned = 0;

            // 反转
            for (int temp = n; temp > 0; temp /= 10) {
                int m = temp % 10;
                turned = turned * 10 + m;
            }

            if (original == turned) {
                printf("%d\n", original);
                break;
            } else n++;
            
        }
    }
    
}
