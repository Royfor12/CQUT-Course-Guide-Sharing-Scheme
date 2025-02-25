#include <stdio.h>
#include <math.h>

int main() {
    int numbers[20];
    int count1 = 0, count2 = 0, count3 = 0;
    for (int i = 1; i < 21; i++) {
        scanf("%d", &numbers[i]);
        if (numbers[i] > 0) {
            count1++;
        }
        else if (numbers[i] < 0) {
            count2++;
        }
        else {
            count3++;
        }
    }
    printf("正数个数：%d\n负数个数：%d\n零的个数：%d\n", count1, count2, count3);

return 0;
}
