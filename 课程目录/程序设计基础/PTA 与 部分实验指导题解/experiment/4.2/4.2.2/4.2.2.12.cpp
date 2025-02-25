#include <stdio.h>

int main() {
    int year, month, day;

    printf("请输入年份：");
    scanf("%d", &year);
    printf("请输入月份：");
    scanf("%d", &month);
    printf("请输入日期：");
    scanf("%d", &day);

    printf("| %d年 | %d月 | %d日 |\n", year, month, day);

return 0;
}