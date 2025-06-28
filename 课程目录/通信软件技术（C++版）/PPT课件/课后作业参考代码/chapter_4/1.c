#include <stdio.h>

int main(void)
{
    static const char *year_name[] = {"鼠", "牛", "虎", "兔",
                                      "龙", "蛇", "马", "羊", 
                                      "猴", "鸡", "狗", "猪"};

    printf("%s\n", year_name[2 + (29 % 12)]);

    return 0;
}
