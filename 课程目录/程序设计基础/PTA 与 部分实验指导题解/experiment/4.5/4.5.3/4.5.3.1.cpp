#include <stdio.h>
#include <time.h>

int main(void)
{
    int num[15];
    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        num[i] = rand();
    }
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
return 0;
}