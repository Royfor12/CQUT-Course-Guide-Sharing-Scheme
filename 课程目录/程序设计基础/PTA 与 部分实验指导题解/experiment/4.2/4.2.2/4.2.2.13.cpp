#include <stdio.h>
int main(){
    float c, f;

    printf("请输入摄氏度：");
    scanf("%f", &c);

    f = (c * 9 / 5) + 32;

    printf("对应的华氏度为: %.2f\n", f);

return 0;
}