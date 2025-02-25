/**********************************

输入一个正整数 repeat (0<repeat<10)，做 repeat 次下列运算：

输入一个字符串 str，再输入一个字符 c，将字符串 str 中出现的所有字符 c 删除。

要求定义并调用函数delchar(str,c), 它的功能是将字符串 str 中出现的所有 c 字符删除，函数形参str的类型是字符指针，形参c的类型是char，函数类型是void。

输入输出示例：括号内为说明，无需输入输出

输入样例:
3               (repeat=3）
happy new year  (字符串"happy new year")
a               (待删除的字符'a')
bee             (字符串"bee")
e               (待删除的字符'e')
111211          (字符串"111211")
1               (待删除的字符'1')

输出样例:
result: hppy new yer    (字符串"happy new year"中的字符'a'都被删除)
result: b               (字符串"bee"中的字符'e'都被删除)
result: 2               (字符串"111211"中的字符'1'都被删除)

***********************************/

#include <stdio.h>

void delchar(char *str, char c) {
    int i, j;
    for (i = 0; str[i]!= '\0'; i++) {
        if (str[i] == c) {
            for (j = i; str[j]!= '\0'; j++) {
                str[j] = str[j + 1];  // 将后面的字符赋值给当前字符，实现删除操作
            }
            i--;  // str长度减一
        }
    }
}

int main() {
    int repeat;
    char str[100], c;
    int i;
    scanf("%d", &repeat);
    for (i = 0; i < repeat; i++) {
        scanf("%s", str);
        getchar();  // 读取换行符
        scanf("%c", &c);
        delchar(str, c);
        printf("result: %s\n", str);
    }
    return 0;
}