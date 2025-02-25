/**********************************

给定平面上任意三个点的坐标(x1,y1)、(x2,y2)、(x3,y3)，检验它们能否构成三角形。

输入格式:
输入在一行中顺序给出六个[−100,100]范围内的数字，即三个点的坐标x1、y1、x2、y2、x3、y3。 

输出格式:
若这3个点不能构成三角形，则在一行中输出“Impossible”；若可以，则在一行中输出该三角形的周长和面积，格式为“L = 周长, A = 面积”，输出到小数点后2位。

输入样例1:
4 5 6 9 7 8

输出样例1:
L = 10.13, A = 3.00

输入样例2:
4 6 8 12 12 18

输出样例2:
Impossible

***********************************/

#include <stdio.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    double a = distance(x1, y1, x2, y2);
    double b = distance(x2, y2, x3, y3);
    double c = distance(x3, y3, x1, y1);
    
    if (a + b > c && a + c > b && b + c > a) {
        double l = a + b + c;

        double m = l / 2;
        double s = sqrt(m * (m - a) * (m - b) * (m - c));
        
        printf("L = %.2f, A = %.2f\n", l, s);
    } else {
        printf("Impossible\n");
    }
    
return 0;
}