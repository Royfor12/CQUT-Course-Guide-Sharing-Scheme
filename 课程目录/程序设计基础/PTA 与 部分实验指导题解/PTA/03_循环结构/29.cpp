/**********************************

彩票的号码有 6 位数字，若一张彩票的前 3 位上的数之和等于后 3 位上的数之和，则称这张彩票是幸运的。本题就请你判断给定的彩票是不是幸运的。

输入格式：
输入在第一行中给出一个正整数 N（≤ 100）。随后 N 行，每行给出一张彩票的 6 位数字。

输出格式：
对每张彩票，如果它是幸运的，就在一行中输出 You are lucky!；否则输出 Wish you good luck.。

输入样例：
2
233008
123456

输出样例：
You are lucky!
Wish you good luck.

***********************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num, a, b, c, d, e, f;
        scanf("%d", &num);
        a = num / 100000;
        b = num / 10000 % 10;
        c = num / 1000 % 10;
        d = num / 100 % 10;
        e = num / 10 % 10;
        f = num % 10;

        if (a + b + c == d + e + f) {
            printf("You are lucky!\n");
        } else {
            printf("Wish you good luck.\n");
        }
    }

return 0;
}
