/**********************************

本题要求编写程序，使用指针方式求一个给定的m×n矩阵各行元素之和。

输入格式:
输入第一行给出两个正整数m和n（1≤m,n≤6），再输入m行数据，每行n个整数，每个整数之间用空格分隔。

输出格式:
输出m个整数，每行1个数。

输入样例:
2 3
1 2 3
4 5 6

输出样例:
6
15

***********************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int elem[m][n];
    int *p = (int *)malloc(m * n * sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &elem[i][j]);
            *(p + i * n + j) = elem[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += *(p + i * n + j);
        }
        printf("%d\n", sum);
    }
    free(p);
    return 0;
}