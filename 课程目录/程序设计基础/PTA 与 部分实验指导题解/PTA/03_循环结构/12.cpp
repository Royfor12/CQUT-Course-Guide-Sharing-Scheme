/**********************************

有足够数量的5分、2分和1分的硬币，
现在要用这些硬币来支付一笔小于1元的零钱money，问至少要用多少个硬币？

输入格式:
输入在一行中给出零钱数额money∈[1,100)。

输出格式:
输出在一行中给出每种硬币的数量和总数量，格式为：

fen5:5分硬币数量, fen2:2分硬币数量, fen1:1分硬币数量, total:硬币总数量
请注意：逗号后有一个空格，冒号后没有空格。

输入样例:
12

输出样例:
fen5:2, fen2:1, fen1:0, total:3

***********************************/

#include <stdio.h>

int main() {
    int money;
    scanf("%d", &money);

    int fen5 = money / 5;
    money %= 5;
    int fen2 = money / 2;
    money %= 2;
    int fen1 = money;

    printf("fen5:%d, fen2:%d, fen1:%d, total:%d", fen5, fen2, fen1, fen5 + fen2 + fen1);

return 0;
}
