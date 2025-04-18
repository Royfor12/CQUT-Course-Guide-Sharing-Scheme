/*********************************************************************
    程序名: 100元买100只鸡的问题
    版  权:免费
    作  者:丁朝远
    日  期: 2024-10-29 17:47
    说  明:c语言循环程序设计练习
*********************************************************************/
//设x,y,z是买到的公鸡、母鸡和小鸡的数量
//公鸡的最大数量不超过34；买到的小鸡数量是3的整数倍

#include <stdio.h>

int main() {
	int x, y, z;
	printf("公鸡   母鸡    小鸡\n");
	printf("————————————\n");
	for (x = 0; x <= 33; x++)
		for (y = 0; y <= 100; y++)
			for (z = 0; z <= 100; z = z + 3 ) {

				if (3 * x + y + z / 3 == 100 && x  + y + z == 100)
					printf("  %d\t%d\t%d\n", x, y, z);
			}
	printf("————————————\n");
	return 0;
}
