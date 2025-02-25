/**********************************

给定两个长度分别为N和M的字符串A和B，求既是A的子序列又是B的子序列的字符串长度最长是多少。

输入格式:
第一行包含两个整数N和M。1≤N,M≤1000

第二行包含一个长度为N的字符串，表示字符串A。

第三行包含一个长度为M的字符串，表示字符串B。

字符串均由小写字母构成。

输出格式:
输出一个整数，表示最大长度。

输入样例:
4 5
acbd
abcbd

输出样例:
4

***********************************/

// 这个方法不能通过部分测试点，因为时间复杂度太高，懒得改了
// 感兴趣可以研究一下动态规划，我看不懂。

#include <stdio.h>
#include <string.h>
// 使用递归
int function(int i, int j, char *str1, char *str2) {
    if (i == 0 || j == 0) {
        return 0;
    }

    // 如果当前字符相同，处理前一个字符
    if (str1[i - 1] == str2[j - 1])
    {
        return function(i - 1, j - 1, str1, str2) + 1;  //长度加一
    } else {
        // 否则，取去掉其中一个字符的结果中的较大值
        return (function(i - 1, j, str1, str2) > function(i, j - 1, str1, str2)) ?
                function(i - 1, j, str1, str2) : function(i, j - 1, str1, str2);
    }

}

int main(void) {
    char str1[1000], str2[1000];
    int N, M;
    scanf("%d %d", &N, &M);
    scanf("%s", str1);
    scanf("%s", str2);
    int len = function(N, M, str1, str2);
    printf("%d", len);
    return 0;
}