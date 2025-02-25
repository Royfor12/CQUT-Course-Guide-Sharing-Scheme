/**********************************

本题要求将给定的n个整数从大到小排序后输出。

输入格式：
输入第一行给出一个不超过10的正整数n。
第二行给出n个整数，其间以空格分隔。

输出格式：
在一行中输出从大到小有序的数列，相邻数字间有一个空格，行末不得有多余空格。

输入样例：
4
5 1 7 6

输出样例：
7 6 5 1

***********************************/

//题目要求用选择法，那就勉为其难用一下
#include <stdio.h>
int main(void) {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        //设当前 i 是最大元素的位置
        int max = i;

        //在剩下的元素中找到最大值的索引
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max]) {
                max = j;  //更新最大元素的索引
            }
        }

        //如果最大元素不是当前元素，交换
        if (max != i) {
            int temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }

    int first = 1;
    for (int i = 0; i < n; i++) {
        if (first) {
            printf("%d", arr[i]);
            first = 0;
        } else {
            printf(" %d", arr[i]);
        }
    }

    printf("\n");

return 0;
}
