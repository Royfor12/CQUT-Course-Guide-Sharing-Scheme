/**********************************

对一元二次方程ax^2+bx+c=0，输入该方程的三个实系数a,b,c（输入的数值应保证方程有实根），计算并输出该方程的两个实根。

输入格式:
输入在一行中给出2三个实系数a,b,c

输出格式:
在一行中输出方程的两个实根。

输入样例:
3.0 4.0 1.0

输出样例:
v1=-1.00,v2=-0.33

**********************************/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        double delta = b * b - 4 * a * c;
        if (delta >= 0) {
            double v1 = (-b + sqrt(delta)) / (2 * a);
            double v2 = (-b - sqrt(delta)) / (2 * a);
            printf("v1=%.2f,v2=%.2f", v2, v1);
        }
    }
return 0;
}