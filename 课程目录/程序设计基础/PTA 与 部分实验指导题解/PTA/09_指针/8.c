/**********************************

读入n个整数，调用max_min()函数求这n个数中的最大值和最小值。

输入格式:
输入有两行：
第一行是n值；
第二行是n个数。

输出格式:
输出最大值和最小值。

输入样例:
在这里给出一组输入。例如：
5
8 9 12 0 3

输出样例:
在这里给出相应的输出。例如：
max = 12
min = 0

***********************************/

#include <stdio.h>

void max_min(int a[], int n, int *max, int *min) {
    *max = *min = a[0];  // 初始化max和min
    for (int i = 1; i < n; i++) {
        if (a[i] > *max)
            *max = a[i];
        if (a[i] < *min)
            *min = a[i];
    }
}

int main(void) {
    int n, a[100], max, min;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max_min(a, n, &max, &min);

    printf("max = %d\nmin = %d\n", max, min);
    return 0;
}