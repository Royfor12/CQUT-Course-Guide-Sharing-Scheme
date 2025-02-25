/**********************************

不变初心数是指这样一种特别的数，它分别乘 2、3、4、5、6、7、8、9 时，所得乘积各位数之和却不变。
例如 18 就是这样的数：18 的 2 倍是 36，3+6=9；18 的 3 倍是 54，5+4=9；…… 18 的 9 倍是 162，1+6+2=9。
对于 18 而言，9 就是它的初心。本题要求你判断任一个给定的数是否有不变的初心。

输入格式：
输入在第一行中给出一个正整数 N（≤ 100）。随后 N 行，每行给出一个不超过 10^5的正整数。

输出格式：
对每个给定的数字，如果它有不变的初心，就在一行中输出它的初心；否则输出 NO。

输入样例：
4
18
256
99792
88672

输出样例：
9
NO
36
NO

***********************************/

#include <stdio.h>
int input;
int chuxin(int input) {
    int sum1 = 0, sum2 = 0;

    int is_chuxin = 1; // 用于判断是否有不变的初心

    for (int i = 2; i < 10; i++) {
        int product = input * i;
        sum1 = 0;

        // 提取最后一位并累加
        while (product > 0) {
            sum1 += product % 10; 
            product /= 10;
        }
        
        if (i == 2) {
            sum2 = sum1;  // sum2用于存储第一个循环的各位数之和
        } else if (sum1 != sum2) {
            is_chuxin = 0;  // 不是"不变的初心"
            break;
        }
    }

    if (is_chuxin) {  // 是，则输出
        return sum1;
    } else {
        return 0;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &input);
        int result = chuxin(input);
        if (result != 0) {
            printf("%d\n", result);
        } else {
            printf("NO\n");
        }
    }

return 0;
}




