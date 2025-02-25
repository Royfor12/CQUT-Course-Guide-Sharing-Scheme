/**********************************

本题目要求一元二次方程ax^2＋bx＋c＝0的根，结果保留2位小数。（注意：0.00会在gcc下被输出为-0.00，需要做特殊处理，输出正确的0.00。）

输入格式:
输入在一行中给出3个浮点系数a、b、c，中间用空格分开。

输出格式:
根据系数情况，输出不同结果：

1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；

2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；

3)如果方程只有一个根，则直接输出此根；

4)如果系数都为0，则输出"Zero Equation"；

5)如果a和b为0，c不为0，则输出"Not An Equation"。

输入样例1:
2.1 8.9 3.5

输出样例1:
-0.44
-3.80

输入样例2:
1 2 3

输出样例2:
-1.00+1.41i
-1.00-1.41i

输入样例3:
0 2 4

输出样例3:
-2.00

输入样例4:
0 0 0

输出样例4:
Zero Equation

输入样例5:
0 0 1

输出样例5:
Not An Equation

***********************************/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2, x;
    scanf("%lf %lf %lf", &a, &b, &c);
    delta = b * b - 4 * a * c;

    if (a!= 0) {
        if (delta > 0) {
            x1 = (-b + sqrt(delta)) / (2 * a);
            x2 = (-b - sqrt(delta)) / (2 * a);
            x1 = (x1 == -0.00)? 0.00 : x1;
            x2 = (x2 == -0.00)? 0.00 : x2;
            printf("%.2lf\n%.2lf", x1, x2);
        } else if (delta == 0) {
            x = -b / (2 * a);
            x = (x == -0.00)? 0.00 : x;
            printf("%.2lf", x);
        } else {
            x1 = -b / (2 * a);
            x2 = sqrt(-delta) / (2 * a);
            x1 = (x1 == -0.00)? 0.00 : x1;
            x2 = (x2 == -0.00)? 0.00 : x2;
            printf("%.2lf+%.2lfi\n%.2lf-%.2lfi", x1, x2, x1, x2);
        }
    } else if (b!= 0) {
        x = -c / b;
        x = (x == -0.00)? 0.00 : x;
        printf("%.2lf", x);
    } else if (c!= 0) {
        printf("Not An Equation");
    } else {
        printf("Zero Equation");
    }

    return 0;
}