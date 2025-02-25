#include <stdio.h>
#include <string.h>

struct student
{
    char id[20];
    char name[20];
    float score1;
    float score2;
    float score3;
    float average;
};struct student stu[5];

int main() {
    for (int i = 0; i < 5; i++) {
        printf("请输入第%d个学生的学号：\n", i + 1);
        scanf("%s", stu[i].id);
        printf("请输入第%d个学生的姓名：\n", i + 1);
        scanf("%s", stu[i].name);
        printf("请输入第%d个学生的三门课成绩：\n", i + 1);
        scanf("%f %f %f", &stu[i].score1, &stu[i].score2, &stu[i].score3);
        stu[i].average = (stu[i].score1 + stu[i].score2 + stu[i].score3) / 3;
    }
    float total_average = 0;
    for (int i = 0; i < 5; i++) {
        total_average += stu[i].average;
    }
    total_average /= 5;

    int max_index = 0;  
    for (int i = 1; i < 5; i++) {
        if (stu[i].average > stu[max_index].average) {
            max_index = i;
        }
    }

    printf("三门课的平均成绩为：%.2f\n", total_average);
    printf("最高分的学生是：%s，学号为：%s，平均分为：%.2f\n", stu[max_index].name, stu[max_index].id, stu[max_index].average);
    return 0;
}
