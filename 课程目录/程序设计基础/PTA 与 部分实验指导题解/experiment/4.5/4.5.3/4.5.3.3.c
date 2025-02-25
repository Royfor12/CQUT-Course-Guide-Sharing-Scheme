#include <stdio.h>
#include <time.h>
#define legth 1000
int main(void)
{
    int num[legth];
    srand(time(NULL));
    for (int i = 0; i < legth; i++)
    {
        num[i] = rand();
    }

    for (int i = 0; i < legth; i++)
    {
        int temp = num[i];
        num[i] = num[legth - 1 - i];
        num[legth - 1 - i] = temp;
    }
return 0;
}