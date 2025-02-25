/**********************************

从键盘输入一个学生五门课的成绩分数，分数为0-100之间的整数。计算并输出该学生的平均分。

输入格式:
输入在一行中给出5门课程的分数，每个分数之间用空格分开。

输出格式:
对每一组输入，在一行中输出分数的平均值，小数点后面保留两位。

输入样例:
在这里给出一组输入。例如：
70 80 94 66 84

输出样例:
在这里给出相应的输出。例如：
78.80

**********************************/

#include <stdio.h>
int main() {
    int score1, score2, score3, score4, score5;
    scanf("%d %d %d %d %d", &score1, &score2, &score3, &score4, &score5);

    double average = (score1 + score2 + score3 + score4 + score5) / 5.0;
    printf("%.2f", average);

    return 0;
}
