/**********************************

测试数据有多组，处理到文件尾。
每组测试输入一行，包含一个长度不超过100的英文句子（仅包含大小写英文字母和空格），单词之间以一个空格间隔。

输出格式:
对于每组测试，输出按照要求改写后的英文句子。

输入样例:
I like acm
i want to get Accepted

输出样例:
I Like Acm
I Want To Get Accepted

***********************************/

#include <stdio.h>
#include <string.h>

int main() {
    char sentence[101];
    int first = 1;

    while(fgets(sentence, 101, stdin) != NULL) {

        // 去除换行符
        int len = strlen(sentence);
        if(sentence[len-1] == '\n') {
            sentence[len-1] = '\0';
            len--;
        }
        
        int Caps = 1;  // 标记是否应该大写
        for(int i = 0; i < len; i++) {
            // 是否为字母
            if(Caps && ((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z'))) {
                if(sentence[i] >= 'a' && sentence[i] <= 'z') {
                    sentence[i] = sentence[i] - 'a' + 'A';
                }
                Caps = 0;
            } else if(sentence[i] == ' ') {
                Caps = 1;
            }
        }
        
        if (first) {
            printf("%s", sentence);
            first = 0;
        } else {
            printf("\n%s", sentence);
        }
        
    }
    
    return 0;
}