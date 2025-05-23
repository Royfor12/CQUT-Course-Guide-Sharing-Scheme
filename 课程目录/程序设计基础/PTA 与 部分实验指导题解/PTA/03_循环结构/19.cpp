/**********************************

判断一个int型整数是否是2的n次方，如果是则输出n值，否则输出NO!。

输入格式:
输入若干个整数，以空格或换行间隔。

输出格式:
对每一个整数，在一行中输出n值或“NO！”。

打印一个由 m 行字符 * 组成的倒置的直角三角形图案。

输入格式:
输入一个整数，表示行数 m，其中 m 满足 2≤m≤10。

输出格式:
由字符 * 组成的 m 行倒立直角三角形图案。

输入样例:
5

输出样例:
*****
 ****
  ***
   **
    *

***********************************/

#include <stdio.h>

int main() {
    int i, j, n;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            printf(" ");
        }
        for (j = i; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }

return 0;
}