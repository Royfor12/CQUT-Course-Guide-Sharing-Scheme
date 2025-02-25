/**********************************

本题要求编写程序计算某年某月某日是该年中的第几天。

输入格式:
输入在一行中按照格式“yyyy/mm/dd”（即“年/月/日”）给出日期。注意：闰年的判别条件是该年年份能被4整除但不能被100整除、或者能被400整除。闰年的2月有29天。 

输出格式:
在一行输出日期是该年中的第几天。

输入样例1:
2009/03/02

输出样例1:
61

输入样例2:
2000/03/02

输出样例2:
62

***********************************/

#include <iostream>
using namespace std;

bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100!= 0) || (year % 400 == 0);
}

int main() {
    int year, month, day;
    char slash;
    cin >> year >> slash >> month >> slash >> day;

    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (LeapYear(year)) daysInMonth[2] = 29;

    int days = 0;
    for (int i = 1; i < month; i++) {
        days += daysInMonth[i];
    }

    days += day;

    cout << days;

    return 0;
}