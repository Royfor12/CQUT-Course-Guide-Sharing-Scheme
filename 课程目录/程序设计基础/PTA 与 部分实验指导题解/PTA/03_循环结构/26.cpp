/**********************************

判断一个int型整数是否是2的n次方，如果是则输出n值，否则输出NO!。

输入格式:
输入若干个整数，以空格或换行间隔。

输出格式:
对每一个整数，在一行中输出n值或“NO！”。

输入样例1:
2 8 15

输出样例1:
在这里给出相应的输出。例如：

1
3
No!

输入样例2
-8
0

输出样例2:
在这里给出相应的输出。例如：

3
No!

***********************************/

#include <stdio.h>
#include <stdint.h>

int main(void) {
    int64_t num;  //傻逼题目，32位的int不够用，直接溢出了
    while (scanf("%lld", &num) != EOF) {
        if (num < 0) num = -num;
        if (num == 0) {
            printf("No!\n");
            continue;
        }
        int n = 0;
        while (num > 1) {
            if (num % 2 != 0) {
                printf("No!\n");
                break;
            }
            num /= 2;
            n++;
        }
        if (num == 1) printf("%d\n", n);
    }
}
