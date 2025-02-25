#include <stdio.h>

struct info1
{
    char name;
    int birth_year;
}

struct info2
{
    char social_security_no[10];
    struct info1 basic;
};

int main() {
    struct info2 people[5] = {
        {
            "114514191",
            {"John", 1985}
        },
        {
            "111212121",
            {"Alice", 1999}
        },
        {
            "122484845",
            {"Jenny", 2003}
        },
        {
            "465899094",
            {"Hawark", 2013}
        },
        {
            "123123123",
            {"Bob", 1984}
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("第%d个人的基本信息：\n", i + 1);
        printf("姓名：%s\n", people[i].basic.name);
        printf("出生年份：%d\n", people[i].basic.birth_year);
        printf("社保号码：%s\n", people[i].social_security_no);
    }
    return 0;
}

