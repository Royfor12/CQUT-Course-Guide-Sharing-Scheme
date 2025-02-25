/**********************************

对于给定的数列，要求把其中的重复元素删去再从小到大输出。

输入格式:
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据先输入一个整数n（1≤n≤100），再输入n个整数。 

输出格式:
对于每组测试，从小到大输出删除重复元素之后的结果，每两个数据之间留一个空格。 

输入样例:
1
10 1 2 2 2 3 3 1 5 4 5

输出样例:
1 2 3 4 5

***********************************/




/*******************************************************    
第一版
下面的代码是错的，不用看

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int count[101] = {0};
    for (int i = 0; i < n; i++) {
        int score;
        scanf("%d", &score);
        count[score]++;
    }
    int turned_scores[101];  
    //这道题直接引用了第二题的功能，先排序了再删，懒得重新写
    //turned_scores[n]存储排序后的分数

    int k = 0;  // 用于 turned_scores 的下标
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < count[i]; j++) {
            turned_scores[k++] = i;  // 将分数升序存储到turned_scores中
        }
    }

    //以下部分涉及指针，还没学，看不懂就算了

    int j = 0;  //慢指针，指向已去重的数组
    for (int i = 1; i < k; i++) {
        if (turned_scores[i]!= turned_scores[j]) {
            j++;
            turned_scores[j] = turned_scores[i];  //将当前元素放到去重数组的下一个位置
        }
    }

    ********************************************************************************************
    唉还是举个例子吧
    假设我们有一个已经按升序排序的数组
    turned_scores = [1, 1, 2, 2, 2, 3, 3, 4, 5, 5]

    初始化：
    j = 0，指向数组的第一个位置。
    i = 1，指向数组的第二个位置。

    第一步：i = 1，检查[1] 和 [0]
    [1] = 1 和 [0] = 1 相同，i++，不做任何操作。

    第二步：i = 2，检查[2] 和 [0]
    [2] = 2 和 [0] = 1 不相同，表示遇到了新的元素 2。
    于是我们先将j+1，
    再把turned_scores [2] 放到 turned_scores[j]的位置，[j]=[1]
    当前 turned_scores 数组变为 [1, 2, 2, 2, 2, 3, 3, 4, 5, 5]。

    以此类推
    [1, 2, 3, 2, 2, 3, 3, 4, 5, 5]
    [1, 2, 3, 4, 2, 3, 3, 4, 5, 5]
    [1, 2, 3, 4, 5, 3, 3, 4, 5, 5]
    ……
    [1, 2, 3, 4, 5]
    
    你可能想问，最后的 3，3，4，5 在输出的数组中怎么消失了呢
    其实这些被跳过的元素并没有被实际删除，它们仍然存在于原数组中，只是它们的位置没有被修改，而是被忽略了
    因为最后j 的值为 5，即去重后的数组的长度，我们只输出到第五个位置，后面的就不管了。
    *********************************************************************************************

    int first = 1;
    for (int i = 0; i <= j; i++) {  //这里就体现了只输出到j的位置
        if (first) {
            printf("%d", turned_scores[i]);
            first = 0;
        } else {
            printf(" %d", turned_scores[i]);
        }
    }
    printf("\n");
}
*******************************************************/

/*******************************************************
 * 第二版
该题实质上跟第2题是一样的，count只存储出现的次数，打印只输出一次，不需要指针
傻逼PTA，结果都一样，就是判错，只能又重新写

#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n;
        scanf("%d", &n);
        
        int count[101] = {0};
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            count[num]++;
        }
        
        int first = 1;
        for (int i = 1; i <= 100; i++) {
            if (count[i] > 0) {
                if (first) {
                    printf("%d", i);
                    first = 0;
                } else {
                    printf(" %d", i);
                }
            }
        }
        printf("\n");
    }
}
*******************************************************/

#include <stdio.h>

int main(void){
    
    int T, n;
    scanf("%d", &T);
    
    for(int i = 1; i <= T; i++){
        int num[101];
        scanf("%d", &n);
        
        for(int i = 0; i < n; i++){
            scanf("%d", &num[i]);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){  //判断num[i]后边的数是否和num[i]相等
                if(num[i] == num[j]){
                    for(int temp = j; temp < n - 1; temp++){
                        num[temp] = num[temp + 1];  //将num[j]后面的元素全往前移一个位置
                    }
                    j--;  //num[j+1]取代num[j]位置，为使下次从num[j+1]开始查找,j减一(为使j保持不变)
				    n--;  //数组长度减一
                }
            }
        }
        
        int temp;
        //排序
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1 - i; j++){
                if(num[j] > num[j+1]){
                    temp = num[j+1];
                    num[j+1] = num[j];
                    num[j] = temp;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i != n-1)
            printf("%d ",num[i]);
            else
                printf("%d\n", num[i]);
        }
        
    }
}





