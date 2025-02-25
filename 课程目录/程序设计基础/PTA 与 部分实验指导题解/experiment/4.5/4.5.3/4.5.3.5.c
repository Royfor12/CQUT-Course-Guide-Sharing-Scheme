#include <stdio.h>

int main(void)
{
    float score[5][3] = {0};
    float sum[5] = {0};
    float avg[5] = {0};
    int count = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f", &score[i][j]);
            sum[i] += score[i][j];
        }
        avg[i] = sum[i] / 3;
        if (avg[i] < 60)
        {
            count++;
        }
    }
    
    for (size_t i = 0; i < count; i++)
    {
        /* code */
    }
    
}
