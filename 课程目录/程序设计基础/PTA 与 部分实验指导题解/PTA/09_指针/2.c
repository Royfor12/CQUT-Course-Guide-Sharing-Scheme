/**********************************

输入一个正整数repeat (0<repeat<10)，做repeat次下列运算：

输入一个正整数 n (1<n<=10)，然后输入n个整数存入数组a中，再输入一个整数x，在数组a中查找x，
如果找到则输出相应元素的最小下标，否则输出"Not found"。

要求定义并调用函数search(list, n, x)，它的功能是在数组list中查找元素x，
若找到则返回相应元素的最小下标，否则返回-1，函数形参 list 的类型是整型指针，形参n和x的类型是int，函数的类型是int。

输出格式语句：printf("index = %d\n", );

输入输出示例：括号内为说明，无需输入输出

输入样例:
2              (repeat=2) 
3              (n=3)
1 2 -6        
2              (x=2)
5              (n=5)
1 2 2 5 4
0              (x=0)

输出样例:
index = 1
Not found

***********************************/

#include<stdio.h>

int search(int *list, int n, int x) {
    for (int i = 0; i < n; i++)
    {
        if (*(list + i) == x)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int repeat;
    scanf("%d", &repeat);
    for (int j = 0; j < repeat; j++)
    {
        int n;
        scanf("%d", &n);

        int list[n];
        for (int k = 0; k < n; k++)
        {
            scanf("d", &list[k]);
        }
        
        int x;
        scanf("d", &x);

        int index = search(&list[0], n, x);
        if (index != -1)
        {
            printf("index = %d\n", index);
        } else {
            printf("Not found\n");
        }
    }
    return 0;
}