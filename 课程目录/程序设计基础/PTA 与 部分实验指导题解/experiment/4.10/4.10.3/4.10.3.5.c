struct staff
{
    char id[5];
    char name[8];
    float salary_rate;
    float work_hours;
};

#include <stdio.h>
#include <string.h>

int main() {
    struct staff staff[6];
    for (int i = 0; i < 6; i++) {
        printf("请输入第%d个员工的工号：\n", i + 1);
        scanf("%s", staff[i].id);
        printf("请输入第%d个员工的姓名：\n", i + 1);
        scanf("%s", staff[i].name);
        printf("请输入第%d个员工的工资系数：\n", i + 1);
        scanf("%f", &staff[i].salary_rate);
        printf("请输入第%d个员工的工作时长：\n", i + 1);
        scanf("%f", &staff[i].work_hours);
    }

    for (int i = 0; i < 6; i++) {
        printf("第%d个员工的工资为：%.2f\n", i + 1, staff[i].salary_rate * staff[i].work_hours);
    }
    
    return 0;
}