/**********************************

数组指针作函数参数
输入m个学生（最多30人）n门课程（最多5门）的成绩，然后计算并打印每个学生各门课的总分和平均分。其中，m和n的值由用户从键盘输入。

输入格式:
输入顺序如下：

学生个数m 课程数n
学生1课程1分数 学生1课程2分数 ... 学生1课程n分数
学生2课程1分数 学生2课程2分数 ... 学生2课程n分数
...
学生m课程1分数 学生m课程2分数 ... 学生m课程n分数

输出格式:
每个学生总分（整数） 平均分（实数，保留1位小数）

输入样例:
在这里给出一组输入。例如：
2 3
61 62 70
75 82 90

输出样例:
在这里给出相应的输出。例如：
193 64.3
247 82.3

***********************************/

#include <stdio.h>

void calculate(int *scores, int m, int n) {
    for (int i = 0; i < m; i++)
    {
        int total = 0;
        for (int j = 0; j < n; j++)
        {
            total += *(scores + i * n + j);  // 为什么这样写，详见第5题注释
        }
        double average = (double)total / n;  // 强制转换为double类型，否则会丢失精度
        printf("%d %.1lf\n", total, average);
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int scores[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &scores[i][j]);
        }
    }

    calculate(&scores[0][0], m, n);

    return 0;
}