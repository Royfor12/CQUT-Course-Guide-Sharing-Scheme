/**********************************

有m个选手n个评委，每个评委给所有选手打分。最后得分的计算规则为去掉一个最高分，去掉一个最低分后取平均分为最后得分。
要求按得分从高到低排出名次，公布获奖名单。
本题要求用行指针实现。1≤m,n≤10。请务必用冒泡排序。

输入格式:
输入共m+1行，第一行是m和n两个整数，其他行是m×n个整数。

输出格式:
输出一行，表示选手编号的一种排列（用%3d格式），这种排列代表得分从高到低的选手顺序。

输入样例:
8 5
7 8 9 7 8
8 9 7 9 8
8 9 8 8 7
8 9 9 9 8
7 6 8 9 7
6 7 8 9 9
6 7 8 7 8
7 8 7 6 7

输出样例:
  4  2  3  6  1  5  7  8

***********************************/

#pragma GCC optimize(3,"Ofast","inline")
#include <stdio.h>

double calculate(int *score, int n) {
    int max = score[0], min = score[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(score + i) > max)
        {
            max = *(score + i);
        }
        if (*(score + i) < min)
        {
            min = *(score + i);
        }
        sum += *(score + i);
    }

    float result = (float)(sum - max - min);
    return result / (n - 2);
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int score[m][n], order[m];
    double final_score[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (*(score + i) + j));
        }
        order[i] = i + 1;
        final_score[i] = calculate(score[i], n);
    }

    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; i < m - 1 - i; j++)
        {
            if (final_score[j] < final_score[j + 1])
            {
                double temp = final_score[j];
                final_score[j] = final_score[j + 1];
                final_score[j + 1] = temp;

                int temp2 = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp2;
            }
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        printf("%3d\n", *(order + i));
    }

    return 0;
}