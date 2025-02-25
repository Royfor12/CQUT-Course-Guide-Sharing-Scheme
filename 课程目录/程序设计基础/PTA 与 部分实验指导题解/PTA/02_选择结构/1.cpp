/**********************************

本题目要求计算下列分段函数f(x)的值：

注：可在头文件中包含math.h，并调用sqrt函数求平方根，调用pow函数求幂。 

输入格式:
输入在一行中给出实数x。

输出格式:
在一行中按“f(x) = result”的格式输出，其中x与result都保留两位小数。

***********************************/

#include <stdio.h>
#include <math.h>

int main() {
    double x;
    scanf("%lf", &x);

    double result;
    if (x < 0) {
        result = pow((x+1), 2) + 2 * x + 1 / x;
    } else {
        result = sqrt(x);
    }

    printf("f(%.2lf) = %.2lf", x, result);

return 0;
}