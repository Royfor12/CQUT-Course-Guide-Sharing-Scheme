/**********************************

本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。

输入格式：
输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。

输出格式：
按照以下格式输出：

average = 平均成绩
max = 最高成绩
min = 最低成绩
结果均保留两位小数。

输入样例：
3
85 90 95

输出样例：
average = 90.00
max = 95.00
min = 85.00

***********************************/

#include<stdio.h>
#include<stdlib.h>
int main() {
	int N;
	scanf("%d", &N);
	double* score = (double*)malloc(N * sizeof(double));  // 动态内存分配

	for (int i = 0; i < N; i++) {
		scanf("%lf", score + i);
	}

	double max = score[0], min = score[0], sum = 0;

	for (int i = 0; i < N; i++) {
		if (score[i] > max) {
			max = score[i];
		}
		if (score[i] < min) {
			min = score[i];
		}
		sum += score[i];
	}

	printf("average = %.2f\n", sum / N);
	printf("max = %.2f\n", max);
	printf("min = %.2f\n", min);

	free(score);  // 释放动态内存

	return 0;
}