#include <stdio.h>

struct info[3]
{
    char name[10];
    int age;
    int salary;
};

struct info info[3] = {
    {"李明", 25, 2500},
    {"王利", 22, 2300},
    {"赵勇", 30, 3000}
}

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%s %d %d\n", info[i].name, info[i].age, info[i].salary);
    }
}