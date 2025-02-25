/**********************************

简易自动售货机，物品架1、2上共有10样商品，按顺序进行编号分别为1－10，标有价格与名称，
一个编号对应一个可操作按钮，供选择商品使用。
如果物架上的商品被用户买走，储物柜中会自动取出商品送到物架上，保证物品架上一定会有商品。
用户可以一次投入较多钱币，并可以选择多样商品，售货机可以一次性将商品输出并找零钱。


用户购买商品的操作方法是：

（1）从“钱币入口”放入钱币，依次放入多个硬币或纸币。
钱币可支持1元（纸币、硬币）、2元（纸币）、5元（纸币）、10元（纸币），
放入钱币时，控制器会先对钱币进行检验识别出币值，并统计币值总额，显示在控制器显示屏中，提示用户确认钱币放入完毕；

（2）用户确认钱币放入完毕，便可选择商品，只要用手指按对应商品外面的编号按钮即可。
每选中一样商品，售货机控制器会判断钱币是否足够购买，
如果钱币足够，自动根据编号将物品进行计数和计算所需钱币值，并提示余额。
如果钱币不足，控制器则提示“Insufficient money”。
用户可以取消购买，将会把所有放入钱币退回给用户。

输入格式:
先输入钱币值序列，以-1作为结束，再依次输入多个购买商品编号，以-1结束。

输出格式:
输出钱币总额与找回零钱，以及所购买商品名称及数量。

输入样例:
1 1 2 2 5 5 10 10 -1
1 2 3 5 1 6 9 10 -1

输出样例:
Total:36yuan,change:19yuan
Table-water:2;Table-water:1;Table-water:1;Milk:1;Beer:1;Oolong-Tea:1;Green-Tea:1;

***********************************/

//代码参考于网络
#include<stdio.h>

int main()
{
    int total = 0, change, money;
    while(1) {
        scanf("%d",&money);
        if(money == -1) break;
        total += money;
    }

    change = total;

    int prize[10] = {1, 1, 1, 2, 2, 3, 3, 3, 4, 4},
        num[10] = {0};

    char products[10][13] = {"Table-water","Table-water","Table-water","Coca-Cola","Milk","Beer",
                            "Orange-Juice","Sprite","Oolong-Tea","Green-Tea"};

    int b;
    while(1) {
        scanf("%d", &b);

        if(b == -1) break;

        change -= prize[b-1];

        if(change < 0){
            printf("Insufficient money");
            return 0;
        }
        num[b-1]++;
    }
    printf("Total:%dyuan,change:%dyuan\n",total, change);

    for(int i = 0; i < 10; i++)
    {
        if(num[i] != 0)
        {
            printf("%s:%d;\n",products[i], num[i]);
        }
    }
    return 0;
}