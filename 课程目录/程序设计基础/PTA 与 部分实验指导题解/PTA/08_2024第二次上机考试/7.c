/**********************************

本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

输入格式：
输入是一个以回车结束的非空字符串（少于80个字符）。

输出格式：
输出去重排序后的结果字符串。

输入样例：
ad2f3adjfeainzzzv

输出样例：
23adefijnvz

***********************************/

#include <stdio.h>
#include <string.h>

void sort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            char temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main() {
    char str[81];
    char final[80];
    int appeared[256] = {0};

    fgets(str, sizeof(str), stdin);

    int n = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && !appeared[str[i]]) {
            final[n++] = str[i];
            appeared[str[i]] = 1;
        }
    }

    sort(final, n);

    for (int i = 0; i < n; i++) {
        printf("%c", final[i]);
    }
    printf("\n");

    return 0;
}