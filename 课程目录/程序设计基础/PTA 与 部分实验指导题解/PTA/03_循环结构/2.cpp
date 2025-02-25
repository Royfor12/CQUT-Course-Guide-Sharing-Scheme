/**********************************

我国古代数学家张丘建在《算经》一书中提出了下述数学问题：
鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，
问鸡翁、鸡母、鸡雏各几何？

请使用三重或者二重循环求解N块钱买N只鸡的问题：计算并输出所有可行的解（须按公鸡，母鸡，小鸡递增排序），以及全部可行解的数量。

输入格式:
整数N

输出格式:
公鸡数,母鸡数,小鸡数 （第1个可行解）
公鸡数,母鸡数,小鸡数 （第2个可行解）
...
公鸡数,母鸡数,小鸡数 （最后1个可行解）
Solution count: 可行解个数.

输入样例:
100

输出样例:
0,25,75
4,18,78
8,11,81
12,4,84
Solution count: 4.

***********************************/

#include <stdio.h>

int Solution(int N) {
    //公鸡是a,母鸡是b,小鸡是c。N既是钱数，也是鸡的数量。
    int a, b, c, count = 0;

    for (c = 0; c <= N; c += 3) { // 小鸡数量
        int remain_Money = N - c / 3; // 剩余的钱
        int remain_Chicken = N - c; // 剩余的鸡

        for (a = 0; a <= remain_Money / 5; a++) {  //公鸡的数量,最多有剩余的钱÷5只
            b = remain_Chicken - a; // 母鸡的数量

            if (b < 0) continue; // 公鸡数量随循环增大，但母鸡数量不能为负，跳出循环

            if (5 * a + 3 * b + c / 3 == N) {
                printf("%d,%d,%d\n", a, b, c);
                count++;
            }
        }
    }

    printf("Solution count: %d.\n", count);
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    Solution(N);
return 0;
}