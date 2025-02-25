/**********************************

每个人都有一个人生密码，只有两个人的人生密码相同，才能走到一起，
给出n个人的人生密码，n是奇数，其中只有一个人的人生密码是单独的，其它都是成对的，请你找出不成对的那一个。

输入格式:
多实例测试，每行第一个数为n(1<=n<=1000000),后面有n个正整数，表示n个人的人生密码 。
n值为0表示输入结束。

输出格式:
输出那个不成对的人生密码。

输入样例:
3 8 9 8
5 120 10 120 10 85
0

输出样例:
在这里给出相应的输出。例如：
9
85

***********************************/

// 注意，该代码存在运行超时的情况，需要使用快速排序
#pragma GCC optimize(3, "Ofast", "inline")
#include <stdio.h>
#include <stdlib.h>
int main() {
    while(1) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        int *arr = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        int found = 0;
        for (int i = 0; i< n - 1; i++) {
            if (arr[i] != arr[i + 1]) {
                printf("%d\n", arr[i]);
                found = 1;
                break;
            }
            i++;
        }
        
        if (!found) {
            printf("%d\n", arr[n - 1]);
        }
        
        free(arr);
    }
    return 0;
}