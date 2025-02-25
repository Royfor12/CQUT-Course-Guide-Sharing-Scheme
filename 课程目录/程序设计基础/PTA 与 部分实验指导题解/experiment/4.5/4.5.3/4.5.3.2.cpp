#include <stdio.h>

int main(void)
{
    int num[20];
    int count[20];
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &num[i]);
        count[i] = i;
    }

    // 排序
    for (int m = 0; m < 20; m++)
    {
        for (int n = 0; n < 20 - m; n++)
        {
            if (num[n] > num[n + 1])
            {
                int temp = num[n];
                num[n] = num[n + 1];
                num[n + 1] = temp;
                // 同时交换索引
                int temp = count[n];
                count[n] = count[n + 1];
                count[n + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%-4d %4d\n", &num[i], &count[i]);
    }
}