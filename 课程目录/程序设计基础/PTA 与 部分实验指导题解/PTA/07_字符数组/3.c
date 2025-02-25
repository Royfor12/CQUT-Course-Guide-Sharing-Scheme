/**********************************

编程序实现如下功能：
从键盘输入一个包含小数的小写金额（整数部分不超过7位），将其转换为汉字大写金额，最后输出结果。

提示：不需要对0进行特殊处理。

输入格式:
输入一个包含小数的小写金额（整数部分不超过7位，小数部分不超过2位）。

输出格式:
汉字大写金额,最后换行。

输入样例:
123.45

输出样例:
壹佰贰拾叁元肆角伍分

***********************************/

/*写了几版都有问题
参考了网上的代码
https://blog.csdn.net/m0_60738889/article/details/136089158
原文写了一堆无意义的函数，可能是出于加密目的。
我就直接修改了，方便理解。
*/

#include <stdio.h>

int main() {

    char *chinese[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
    char *danwei[] = {"元", "拾", "佰", "仟", "万", "拾", "佰", "仟", "亿"};
    double num;

    scanf("%lf", &num);

    int zhengshu_part = (int)num;
    int xiaoshu_part = (int)((num - zhengshu_part + 0.005) * 100);  // 0.005是一个极小值，为了防止浮点数舍入误差
    
    int divisor = 10000000;
    // 提取整数部分的每一位，并输出对应的汉字和单位
    for (int i = 0; i < 8; i++) {
        int digit = zhengshu_part / divisor;
        if (digit != 0) {
            printf("%s%s", chinese[digit], danwei[7-i]);
        }
        zhengshu_part %= divisor;
        divisor /= 10;
    }

    // 整数部分为0的特殊情况
    int k = num;
    if (k == 0) {
        printf("元");
    }

    if (xiaoshu_part != 0) {
        int jiao = xiaoshu_part / 10;
        int fen = xiaoshu_part % 10;
        if(jiao > 0 && fen > 0) {
            printf("%s%s%s%s", chinese[jiao], "角", chinese[fen], "分");
        }
        if(jiao > 0 && fen == 0) {
            printf("%s%s", chinese[jiao], "角");
        }
        if(jiao == 0 && fen > 0) {
            printf("%s%s",chinese[fen], "分");
        }
    }
    return 0;
}