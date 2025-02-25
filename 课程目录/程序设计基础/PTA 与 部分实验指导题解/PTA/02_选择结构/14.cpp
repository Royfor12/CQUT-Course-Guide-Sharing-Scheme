/**********************************

给定一个日期，请判断该日期的第二天是哪年哪月哪日。

输入格式:
输入日期:    年/月/日,其中年是4位整数,月和日是1-2位的整数，输入保证日期是合法的。

输出格式:
按  XXXX-XX-XX格式输出第二天的日期

输入样例1:
在这里给出一组输入。例如：
2022/9/24

输出样例1:
在这里给出相应的输出。例如：
2022-09-25

输入样例2:
在这里给出一组输入。例如：
2022/12/31

输出样例2:
在这里给出相应的输出。例如：
2023-01-01

***********************************/

#include <stdio.h>

bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (LeapYear(year)) daysInMonth[2] = 29;
    day++;

    if (day > daysInMonth[month]) {
        day = 1;
        month++;

        if (month > 12) {
            month = 1;
            year++;
        }
    }

    printf("%4d-%02d-%02d", year, month, day);

return 0;
}