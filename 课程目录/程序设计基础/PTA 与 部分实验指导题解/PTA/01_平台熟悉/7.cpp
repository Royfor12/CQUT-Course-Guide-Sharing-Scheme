/**********************************

输入三个一位整数（0~9之间），输出由其组成的一个整数。例如：输入整数2,4,7，输出247。

输入格式:
输入在一行中给出3个整数，其间用1个空格分开。

输出格式:
对每一组输入，在一行中输出一个计算结果。

输入样例:
在这里给出一组输入。例如：
1 3 5

输出样例:
在这里给出相应的输出。例如：
1 3 5 is changed to 135.

**********************************/

#include <stdio.h>
#include <string.h>  
int main() {
    int num;
    int result = 0;
    char input[100] = "";
    
    while (scanf("%d", &num) == 1) {
        result = result * 10 + num;
        char temp[10];
        sprintf(temp, "%d ", num);
        strcat(input, temp);
    }
    
    printf("%sis changed to %d.", input, result);

return 0;
}
