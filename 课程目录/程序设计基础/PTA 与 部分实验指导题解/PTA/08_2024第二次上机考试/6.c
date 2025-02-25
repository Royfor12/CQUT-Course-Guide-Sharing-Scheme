/**********************************

一个矩阵元素的“鞍点”是指该位置上的元素值在该行上最大、在该列上最小。

本题要求编写程序，求一个给定的n阶方阵的鞍点。

输入格式：
输入第一行给出一个正整数n（1≤n≤6）。随后n行，每行给出n个整数，其间以空格分隔。

输出格式：
输出在一行中按照“行下标 列下标”（下标从0开始）的格式输出鞍点的位置。
如果鞍点不存在，则输出“NONE”。题目保证给出的矩阵至多存在一个鞍点。

输入样例1：
4
1 7 4 1
4 8 3 6
1 6 1 2
0 7 8 9

输出样例1：
2 1

输入样例2：
2
1 7
4 1

输出样例2：
NONE

***********************************/

// 注意，该代码不能通过部分测试点
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[6][6];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int max_val = matrix[i][0];
        int max_col = 0;
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] > max_val) {
                max_val = matrix[i][j];
                max_col = j;
            }
        }

        int is_point = 1;
        for (int m = 0; m < n; m++) {
            if (matrix[m][max_col] < max_val) {
                is_point = 0;
                break;
            }
        }

        if (is_point) {
            printf("%d %d\n", i, max_col);
                return 0;
        }
    }

    printf("NONE\n");
    return 0;
}