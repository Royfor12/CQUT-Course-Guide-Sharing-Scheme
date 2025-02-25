/**********************************

本题要求编写程序，输出2n-1行由大写字母A开始构成的菱形字符阵列。

输入格式:
输入格式：输入在一行中给出一个正整数n（1≤n≤7）。

输出格式:
输出格式：输出2n-1行由大写字母A，B，……，n个开始构成的菱形字符阵列。格式见输出样例。

输入样例:
在这里给出一组输入。例如：

5
输出样例:
在这里给出相应的输出。例如：

    A
   BBB
  CCCCC
 DDDDDDD
EEEEEEEEE
 DDDDDDD
  CCCCC
   BBB
    A

***********************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n - i - 1; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i + 1; j++) {
            printf("%c", 'A' + i);
        }
        printf("\n");
    }


    for (int i = n - 2; i >= 0; i--) {

        for (int j = 1; j <= n - i - 1; j++) {
            printf(" ");
        }

        for (int j = 1; j <= 2 * i + 1; j++) {
            printf("%c", 'A' + i);
        }
        printf("\n");
    }

return 0;
}
