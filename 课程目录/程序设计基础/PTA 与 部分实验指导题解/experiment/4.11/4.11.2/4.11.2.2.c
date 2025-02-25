在以下程序中，用户由键盘输入一个文件名，然后输入一串字符（用#结束输入）
存放到此文件中，形成文本文件，并将字符的个数写到文件尾部。

#include <stdio.h>

void main() {
    FILE *fp;
    char ch, fname[32];
    int count = 0;
    printf("Input a file name: ");
    scanf("%s", fname);
    if ((fp = fopen(fname, "w+")) == NULL)
    {
        /*"w+" 模式的含义：
        如果文件不存在，会创建一个新文件。
        如果文件已存在，会清空其内容。
        文件既可以写入，也可以读取。
        文件指针位置初始化在文件开头。
        */
        printf("Cannot open file %s\n", fname);
        return;
    }
    printf("Enter data: \n");
    while ((ch = getchar())!= '#')
    {
        fputc(ch, fp);  // 逐个字符写入文件
        count++;
    }
    fprintf(fp, "\n%d\n", count);
    fclose(fp);
}