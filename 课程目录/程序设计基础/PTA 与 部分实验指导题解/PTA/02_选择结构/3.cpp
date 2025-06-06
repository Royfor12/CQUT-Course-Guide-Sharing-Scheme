/**********************************

本题要求根据某城市普通出租车收费标准编写程序进行车费计算。具体标准如下：

起步里程为3公里，起步费10元；
超起步里程后10公里内，每公里2元；
超过10公里以上的部分加收50%的回空补贴费，即每公里3元；
营运过程中，因路阻及乘客要求临时停车的，按每5分钟2元计收（不足5分钟则不收费）。
输入格式:
输入在一行中给出输入行驶里程（单位为公里，精确到小数点后1位）与等待时间（整数，单位为分钟），其间以空格分隔。

输出格式:
在一行中输出乘客应支付的车费（单位为元），结果四舍五入，保留到元。

输入样例1:
2.6 2

输出样例1:
10

输入样例2:
5.1 4

输出样例2:
14

输入样例3:
12.5 9

输出样例3:
34

***********************************/

#include <stdio.h>
#include <math.h>

int main() {
    double distance;
    int wait_time;
    scanf("%lf %d", &distance, &wait_time);
    
    double fare = 0.0;

    if (distance <= 3) {
        fare = 10;
    } else if (distance <= 10) {
        fare = 10 + (distance - 3) * 2;
    } else {
        fare = 10 + 7 * 2 + (distance - 10) * 3;
    }

    fare += (wait_time / 5) * 2;

    printf("%.0f\n", round(fare));

return 0;
}