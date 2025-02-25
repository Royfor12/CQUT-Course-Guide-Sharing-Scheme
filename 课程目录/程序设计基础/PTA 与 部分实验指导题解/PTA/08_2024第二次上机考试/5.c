/**********************************

某天，诺诺在做两个10以内（包含10）的加法运算时，感觉太简单。
于是她想增加一点难度，同时也巩固一下英文（学好英文真的很重要！），就把数字用英文单词表示。
为了验证她的答案，请根据给出的两个英文单词表示的数字，计算它们之和并以英文单词的形式输出。

输入格式:
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试输入两个英文单词表示的数字A、B（0≤A，B≤10）。

输出格式:
对于每组测试，在一行上输出A+B的结果，要求以英文单词表示。

输入样例:
2
ten ten 
one two

输出样例:
twenty
three

***********************************/

#include <stdio.h>
#include <string.h>

char* num_to_word[] = {
    "zero","one","two","three","four","five","six","seven","eight",
    "nine","ten","eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen","twenty"
};

int word_to_num(char* word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    if (strcmp(word, "ten") == 0) return 10;
    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        char A[10], B[10];
        scanf("%s %s", A, B);

        int numA = word_to_num(A);
        int numB = word_to_num(B);

        int result = numA + numB;

        printf("%s\n", num_to_word[result]);
    }

    return 0;
}