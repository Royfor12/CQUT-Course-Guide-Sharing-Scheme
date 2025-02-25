/**********************************

给定一个 n×n 的整数矩阵。
对任一给定的正整数 k<n，我们将矩阵的偶数列的元素整体向下依次平移 
1、……、k、1、……、k、…… 个位置，平移空出的位置用整数 x 补。你需要计算出结果矩阵的每一行元素的和。

输入格式：
输入第一行给出 3 个正整数：n（<100）、k（<n）、x（<100），分别如题面所述。

接下来 n 行，每行给出 n 个不超过 100 的正整数，为矩阵元素的值。数字间以空格分隔。

输出格式：
在一行中输出平移后第 1 到 n 行元素的和。数字间以 1 个空格分隔，行首尾不得有多余空格。

输入样例：
7 2 99
11 87 23 67 20 75 89
37 94 27 91 63 50 11
44 38 50 26 40 26 24
73 85 63 28 62 18 68
15 83 27 97 88 25 43
23 78 98 20 30 81 99
77 36 48 59 25 34 22

输出样例：
440 399 369 421 302 386 428

样例解读

需要平移的是第 2、4、6 列。
给定 k=2，应该将这三列顺次整体向下平移 1、2、1 位
（如果有更多列，就应该按照 1、2、1、2 …… 这个规律顺次向下平移），顶端的空位用 99 来填充。
平移后的矩阵变成：

11 99 23 99 20 99 89
37 87 27 99 63 75 11
44 94 50 67 40 50 24
73 38 63 91 62 26 68
15 85 27 26 88 18 43
23 83 98 28 30 25 99
77 78 48 97 25 81 22

***********************************/

#include <stdio.h>
#define Max_Length 100

void shift(int n, int k, int x, int matrix[Max_Length][Max_Length], int result[Max_Length]) {
    int temp[Max_Length]; // 临时数组，用于存储需要移动的列
    int shifted[Max_Length][Max_Length];  // 存储移动后的矩阵

    // 复制原始矩阵到 shifted 数组中
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            shifted[i][j] = matrix[i][j];
        }
    }
    
    for(int col = 1; col < n; col += 2) {
        int shift = (col / 2 % k) + 1;  // 计算当前列需要移动的位数
        
        // 将当前列的元素存储到临时数组中
        for(int i = 0; i < n; i++) {
            temp[i] = matrix[i][col];
        }
        
        // 将临时数组中的元素向下移动 shift 位，并用 x 填充顶部的空位
        for(int i = 0; i < shift; i++) {
            shifted[i][col] = x;
        }
        
        // 将临时数组中的元素向下移动 shift 位，并用原来的元素填充底部的空位
        for(int i = shift; i < n; i++) {
            shifted[i][col] = temp[i-shift];
        }
    }
    
    // 计算每一行的元素和
    for(int i = 0; i < n; i++) {
        result[i] = 0;
        for(int j = 0; j < n; j++) {
            result[i] += shifted[i][j];
        }
    }
}

int main() {
    int n, k, x;
    int matrix[Max_Length][Max_Length];
    int result[Max_Length];
    
    scanf("%d %d %d", &n, &k, &x);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    shift(n, k, x, matrix, result);
    
    for(int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if(i < n-1) printf(" ");
    }
    printf("\n");
    
    return 0;
}