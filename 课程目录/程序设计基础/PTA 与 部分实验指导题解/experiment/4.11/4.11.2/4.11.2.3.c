从键盘输入一个字符串，将其中的小写字母全部转化为大写字母，然后输出到一个磁盘文件"test.dat"中保存,
再从该文件中读出字符串，并显示出来。

#include <stdio.h>
#include <ctype.h>

void function(char *str, char *filename) {
    FILE *file;
    int i = 0;

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }

    while (input[i] != '\0')
    {
        fputc(toupper(input[i]), file);
        i++;
    }

    fclose(file);
}

void read_file(char *filename) {
    FILE *file;
    char ch;
    // 以只读模式打开 test.dat 文件
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件 %s\n", filename);
        return;
    }
    // 逐个字符读取并输出
    while ((ch = fgetc(file))!= EOF) {
        putchar(ch);
    }
    fclose(file);
}

int main() {
    char input[100];

    printf("请输入一个字符串：");
    fgets(input, sizeof(input), stdin);

    function(input, "test.dat");

    printf("文件中的内容是：");

    read_file("test.dat");

    return 0;
}
