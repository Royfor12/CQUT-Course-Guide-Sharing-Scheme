/**********************************

请编写程序，输出字母塔。

输入格式
字母塔高度（不超过 26）

输出格式
指定高度的字母塔

输入样例
5

输出样例
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA

***********************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%c", 'A' + j - 1);
        }
        for (int j = i - 1; j >= 1; j--) {
            printf("%c", 'A' + j - 1);
        }
        printf("\n");

    }
return 0;
}