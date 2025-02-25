/**********************************

医生在书写药品名的时候经常不注意大小写，格式比较混乱。
现要求你写一个程序将医生书写混乱的药品名整理成统一规范的格式，
即药品名的第一个字符如果是字母要大写，其他字母小写。如将ASPIRIN、aspirin整理成Aspirin。

输入描述
第一行一个数字n，表示有n个药品名要整理，n不超过100。
接下来n行，每行一个单词，长度不超过20，表示医生手书的药品名。药品名由字母、数字和-组成。

输出描述
n行，每行一个单词，对应输入的药品名的规范写法。

样例输入
4
AspiRin
cisapride
2-PENICILLIN
Cefradine-6

样例输出
Aspirin
Cisapride
2-penicillin
Cefradine-6

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char str[100][21];  // 20+1
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++) {
        if (str[i][0] >= 'a' && str[i][0] <= 'z') {
            str[i][0] -= 32;
        }
        for (int j = 1; j < strlen(str[i]); j++) {
            if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
                str[i][j] += 32;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}