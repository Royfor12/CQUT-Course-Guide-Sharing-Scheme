#include <stdio.h>
#include <string.h>

//该函数的功能是将字符串 st 的内容逐个字符写入名为 fname 的文件。
void fun(char *fname, char *st) {
    FILE *myf;  // 定义文件指针
    int i;
    myf = fopen(fname, "w");  // 以写方式打开文件
    if (st == NULL)
        return;
    for (i = 0; i < strlen(st); i++)
    {
        fputc(st[i], myf);  // 逐个字符写入文件
    }
    fclose(myf);  // 关闭文件
}

void main() {
    fun("filetest", "new world");
    fun("filetest", "hello");  // 文件是以 "w" 模式打开的，每次写入都会清空文件的原有内容。因此，最终文件中只会保留 "hello"。
}