/**********************************

本题要求输入年份和月份，输出这该月的天数。

输入格式:
输入一行中两个整数，以空格隔开

输出格式:
输出该月的天数。

如果月份错误，则输出ERROR。

输入样例:
2020 1

输出样例:
31

***********************************/

#include <stdio.h>

int main() {
    int year, month;
    scanf("%d %d", &year, &month);

    int days;
    switch (month) {
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12:
            days = 31;
            break;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            days = 30;
            break;
        case 2:
            if ((year % 4 == 0 && year % 100!= 0) || (year % 400 == 0))
                days = 29;
            else
                days = 28;
            break;
        default:
            printf("ERROR\n");
            return 0;
    }

    printf("%d", days);

return 0;
}