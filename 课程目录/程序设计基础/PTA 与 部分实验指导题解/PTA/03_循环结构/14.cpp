
/***********************************

形如a^3= b^3 + c^3 + d^3的等式被称为完美立方等式。
例如123= 63 + 83 + 103 。
编写一个程序，对任给的正整数N (N≤100)，
寻找所有的四元组(a, b, c, d)，
使得a^3 = b^3 + c^3 + d^3，其中a,b,c,d 大于 1, 小于等于N，且b<=c<=d。

输入格式:
一个正整数N (N≤100)。

输出格式:
每行输出一个完美立方。输出格式为：
Cube = a, Triple = (b,c,d)
其中a,b,c,d所在位置分别用实际求出四元组值代入。

请按照a的值，从小到大依次输出。
当两个完美立方等式中a的值相同，则b值小的优先输出、仍相同则c值小的优先输出、再相同则d值小的先输出。

输入样例:
24

输出样例:
Cube = 6, Triple = (3,4,5)
Cube = 12, Triple = (6,8,10)
Cube = 18, Triple = (2,12,16)
Cube = 18, Triple = (9,12,15)
Cube = 19, Triple = (3,10,18)
Cube = 20, Triple = (7,14,17)
Cube = 24, Triple = (12,16,20)

***********************************/

#include <stdio.h>

int main(void) {
    int a, b, c, d, N;
    scanf("%d", &N);

    for (int a = 0; a <= N; a++)
    {
        for (int b = 0; b <= N; b++)
        {
            for (int c = 0; c <= N; c++)
            {
                for (int d = 0; d <= N; d++){
                    if (a*a*a == b*b*b + c*c*c + d*d*d && b <= c && c <= d && b > 1 && a > 1){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
            
        }     
    }
}