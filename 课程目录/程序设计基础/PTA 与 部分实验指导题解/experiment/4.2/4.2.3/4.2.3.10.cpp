#include <stdio.h>

int main() {
    int days;
    printf("输入天数: ");
    scanf("%d", &days);

    int weeks = days / 7;
    int remainDays = days % 7;

    printf("%d 天等于 %d 周 %d 天\n", days, weeks, remainDays);

    return 0;
}
