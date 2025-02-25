/**********************************

在一大堆数据中找出重复的是一件经常要做的事情。现在，我们要处理许多整数，在这些整数中，可能存在重复的数据。

你要写一个程序来做这件事情，读入数据，检查是否有重复的数据。如果有，输出“YES”这三个字母；如果没有，则输出“NO”。

输入格式:
你的程序首先会读到一个正整数n,n∈[1,100000]，然后是n个整数。

输出格式:
如果这些整数中存在重复的，就输出：
YES
否则，就输出：
NO

输入样例:
5
1 2 3 1 4

输出样例:
YES

***********************************/

#include<stdio.h>
int main() {
    int store[100001], repeat = 0, n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &store[i]);
    //考虑n=1的情况
    if(n == 1) {
        printf("NO"); 
        return 0;
    }
    //使用暴力法，与之前所有的数字比较
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
        if(store[i] == store[j]) {
            printf("YES");
            repeat++;
            break;
            }
        }
        if(repeat != 0) 
        break;
    }
    if(repeat == 0) printf("NO");
    
return 0;
}
//用哈希表会报段错误，这是为什么呢