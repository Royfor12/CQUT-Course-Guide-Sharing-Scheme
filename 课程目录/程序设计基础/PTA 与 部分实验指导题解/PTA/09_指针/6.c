/**********************************

输入一个正整数repeat (0<repeat<10)，做repeat次下列运算：

编写程序，输入一个月份，输出对应的英文名称，要求用指针数组表示12个月的英文名称。

若输入月份错误，输出提示信息。

输入输出示例：括号内为说明，无需输入输出

输入样例:
3    (repeat=3)
5
9
14

输出样例:
May
September
Wrong input!

***********************************/

#include <stdio.h>
#include <string.h>

int main(void) {
    int repeat, i, month;
    char *month_name[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    scanf("%d", &repeat);

    for (i = 0; i < repeat; i++) {
        scanf("%d", &month);
        if (month >= 1 && month <= 12)
            printf("%s\n", *(month_name + month - 1));
        else
            printf("Wrong input!\n");
    }

    return 0;
}