/**********************************

请使用指针的方法编写程序，程序的功能是从键盘输入10个数，求其最大值和最小值的差。

输入格式:
输入10个整数，每个整数之间用空格分隔。

输出格式:
同样例。

输入样例:
1 2 3 4 5 6 7 8 9 10

输出样例:
difference value = 9

***********************************/

#include <stdio.h>

int main() {
    int *num[10];

    for (int i = 0; i < 10; i++)
    {
        num[i] = (int *)malloc(sizeof(int));
        scanf("%d", num[i]);
    }

    int max = *num[0], min = *num[0];

    for (int i = 1; i < 10; i++) {
        if (*(num+i) > max) {
            max = *(num+i);
        } else if (*(num+i) < min) {
            min = *(num+i);
        }
    }

    printf("difference value = %d\n", max - min);

    for (int i = 0; i < 10; i++) {
        free(num[i]);
    }

    return 0;
}