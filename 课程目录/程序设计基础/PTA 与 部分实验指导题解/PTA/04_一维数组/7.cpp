/**********************************

一个数组A中存有N（>0）个整数，在不允许使用另外数组的前提下，
将每个整数循环向右移M（≥0）个位置，即将A中的数据由（A0 A1 ⋯ AN−1）
变换为（AN−M ⋯ AN−1 A0 A1 ⋯ AN−M−1）
（最后M个数循环移至最前面的M个位置）。
如果需要考虑程序移动数据的次数尽量少，要如何设计移动的方法？

输入格式:
每个输入包含一个测试用例，第1行输入N（1≤N≤100）和M（≥0）；
第2行输入N个整数，之间用空格分隔。

输出格式:
在一行中输出循环右移M位以后的整数序列，之间用空格分隔，序列结尾不能有多余空格。

输入样例:
6 2
1 2 3 4 5 6

输出样例:
5 6 1 2 3 4

***********************************/

#include <stdio.h>

int main(void) {
    int n, m;
    int a[100];
    int first = 1;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    m = m % n;  //若有数组a[] = {1, 2, 3, 4, 5, 6}，右移7次和右移1次是等效的

    if (m == 0) {  //不需要移动
        for (int i = 0; i < n; i++) {
            if (!first) printf(" ");
            printf("%d", a[i]);
            first = 0;
        }
        printf("\n");
        return 0;
    }

    //反转整个数组
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    //反转前 m 个元素
    for (int i = 0; i < m / 2; i++) {
        int temp = a[i];
        a[i] = a[m - i - 1];
        a[m - i - 1] = temp;
    }

    //反转剩余的 n - m 个元素
    for (int i = m; i < (n + m) / 2; i++) {
        int temp = a[i];
        a[i] = a[n + m - i - 1];
        a[n + m - i - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (!first) printf(" ");
        printf("%d", a[i]);
        first = 0;
    }
    printf("\n");

    return 0;
}
