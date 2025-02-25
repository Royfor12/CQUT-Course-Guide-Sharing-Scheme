/**********************************

给定两个整型数组，本题要求找出不是两者共有的元素。

输入格式:
输入分别在两行中给出两个整型数组，每行先给出正整数N（≤20），随后是N个整数，其间以空格分隔。 

输出格式:
在一行中按照数字给出的顺序输出不是两数组共有的元素，数字间以空格分隔，但行末不得有多余的空格。题目保证至少存在一个这样的数字。同一数字不重复输出。 

输入样例:
10 3 -5 2 8 0 3 5 -15 9 100
11 6 4 8 2 6 -5 9 0 100 8 1

输出样例:
3 5 -15 6 4 1

***********************************/

/***************************************************
第一版逻辑是有问题的，不能合并两个数组再找不重复的，否则数组1内若有重复数字，且这个数字在数组2没有，就不会输出。
第二版的逻辑是先分别对两个数组进行排序去重，再合并为一个新的数组，最后对新的数组进行标记，输出只出现一次的数字。
原因是想整合之前写过的代码的功能，结果写了半天还是错的，这里就不展示了。
#include <stdio.h>
#include <stdint.h>

#define Max_Range 200001
#define Offset 100000  //设定偏移量，用于处理负数

int main() {
    int64_t N1, N2;

    scanf("%lld", &N1);
    int64_t arr1[N1];
    for (int64_t i = 0; i < N1; i++) {
        scanf("%lld", &arr1[i]);
    }
    scanf("%lld", &N2);
    int64_t arr2[N2];
    for (int64_t i = 0; i < N2; i++) {
        scanf("%lld", &arr2[i]);
    }

    //合并两个数组
    int64_t combine[N1 + N2];
    for (int64_t i = 0; i < N1; i++) {
        combine[i] = arr1[i];
    }
    for (int64_t i = 0; i < N2; i++) {
        combine[N1 + i] = arr2[i];
    }

    //标记
    int64_t count[Max_Range] = {0};
    for (int64_t i = 0; i < N1 + N2; i++) {
        count[combine[i] + Offset]++;
    }

    for (int64_t i = 0; i < N1 + N2; i++) {
        if (count[combine[i] + Offset] == 1) {  //只出现一次的数字
            printf("%lld ", combine[i]);
            count[combine[i] + Offset] = 0;  //计数器归为0，避免重复输出
        }
    }

    printf("\n");
    
    return 0;
}
*******************************************/

#include <stdio.h>

int main(void) {
    int n1, n2;
    int arr1[20], arr2[20];
    int i, j;
    
    scanf("%d", &n1);
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]); 
    }
    
    //遍历第一个数组,输出不在第二个数组中的元素
    int first = 1;

    for(i = 0; i < n1; i++) {
        int found = 0;
        //检查当前数字是否在之前已经输出过，避免重复输出
        for(j = 0; j < i; j++) {
            if(arr1[i] == arr1[j]) {
                found = 1;
                break;
            }
        }
        if(found) continue;
        
        //检查是否在第二个数组中存在
        for(j = 0; j < n2; j++) {
            if(arr1[i] == arr2[j]) {
                found = 1;
                break;
            }
        }
        if(!found) {  //如果元素没有在 arr2 中找到，则输出该元素
            if(!first) printf(" ");
            printf("%d", arr1[i]);
            first = 0;
        }
    }
    
    //输出不在第一个数组中的元素
    for(i = 0; i < n2; i++) {
        int found = 0;
        
        for(j = 0; j < i; j++) {
            if(arr2[i] == arr2[j]) {
                found = 1;
                break;
            }
        }
        if(found) continue;
        
        //检查是否在第一个数组中存在
        for(j = 0; j < n1; j++) {
            if(arr2[i] == arr1[j]) {
                found = 1;
                break; 
            }
        }
        if(!found) {
            if(!first) printf(" ");
            printf("%d", arr2[i]);
            first = 0;
        }
    }
    
return 0;
}