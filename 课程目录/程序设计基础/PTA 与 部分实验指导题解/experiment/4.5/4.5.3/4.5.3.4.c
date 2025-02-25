#include <stdio.h>
#include <time.h>
#define legth 1001

int main(void)
{
    int num[legth];
    srand(time(NULL));
    for (int i = 0; i < legth; i++)
    {
        num[i] = rand();
    }
    // 排序
    for (int m = 0; m < 14; m++)
    {
        for (int n = 0; n < 14 - m; n++)
        {
            if (num[n] > num[n + 1])
            {
                int temp = num[n];
                num[n] = num[n + 1];
                num[n + 1] = temp;
            }
        }
    }

    int key;
    scanf("%d", key);