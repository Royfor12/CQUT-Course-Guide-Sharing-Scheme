/**********************************

读入一个实数、一个操作符（仅限于+ - * /）、一个实数，求该表达式的值。若除数为0，输出“The divisor is 0.”

输入格式:
读入操作数、操作符、操作数

输出格式:
输出表达式的值（保留两位小数）。若除数为0，输出“The divisor is 0.”

输入样例:
4/8

输出样例:
0.50

***********************************/

#include <stdio.h>

int main() {
    double num1, num2;
    char operation;

    scanf("%lf %c %lf", &num1, &operation, &num2);
    
    switch(operation) {
        case '+':
            printf("%.2f\n", num1 + num2);
            break;
        case '-':
            printf("%.2f\n", num1 - num2);
            break;
        case '*':
            printf("%.2f\n", num1 * num2);
            break;
        case '/':
            if (num2 == 0) {
                printf("The divisor is 0.\n");
            } else {
                printf("%.2f\n", num1 / num2);
            }
            break;
        default:
            return 1;
            break;
    }
    
return 0;
}