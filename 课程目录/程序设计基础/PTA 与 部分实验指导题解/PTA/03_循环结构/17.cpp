/**********************************

本题要求编写程序对任意给定的头数和足数判断鸡和兔各有多少。  

输入格式:
在一行中给出任意两个非负整数，整数之间用空格分开，第一个整数表示头数，第二个整数表示足数。

输出格式:
在一行中按照chickens = mm; rabbits = nn的格式输出解，如果无解则输出No solution! 。其中mm与nn都是非负整数。

输入样例1:
35 94

输出样例1:
chickens = 23; rabbits = 12

输入样例2:
94 35

输出样例1:
No solution!

***********************************/

#include <stdio.h>

int main(void) {
    int head, leg;
    scanf("%d %d", &head, &leg);

    if (leg % 2 != 0 || leg > 4 * head || leg < 2 * head) {
        // 总足数必为奇数；如果都是兔子，leg上限是4*head；如果都是鸡，leg下限是2*head
        printf("No solution!");
    } else {
        int chickens = 2 * head - leg / 2;
        int rabbits = head - chickens;

        printf("chickens = %d; rabbits = %d", chickens, rabbits);
    }
}
