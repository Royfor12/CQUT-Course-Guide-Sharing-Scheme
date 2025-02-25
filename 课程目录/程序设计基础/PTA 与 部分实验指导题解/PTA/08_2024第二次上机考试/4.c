/**********************************

给定一个长度为n的数组a，请你编写一个函数：

int get_unique_count(int a[], int n);  // 返回数组前n个数中的不同数的个数

输入格式:
第一行包含一个整数n。1≤n≤1000

第二行包含n个整数，表示数组a。

输出格式:
共一行，包含一个整数表示数组中不同数的个数。

输入样例:
5
1 1 2 4 5

输出样例:
4

***********************************/

#include <stdio.h>

int get_unique_count(int a[], int n) {
    int appeared[1001] = {0};
    int unique = 0;

    for (int i = 0; i < n; i++) {
        if(appeared[a[i]] == 0) {
            appeared[a[i]] = 1;
            unique++;
        }
    }

    return unique;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int result = get_unique_count(a, n);
    printf("%d\n", result);

    return 0;
}