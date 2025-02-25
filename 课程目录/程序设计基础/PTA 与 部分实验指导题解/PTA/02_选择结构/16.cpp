/**********************************

自从湖南农业大学、吉首大学和怀化学院组织程序设计课程联考以后，举办联考的经验越来丰富。尤其是在使用PTA系统作为考试平台之后，联考工作得到了很多学校的认可和支持。所以，现在参与联考的学校比较多。为了便于区分考生，考生账号的第一位是学校代号。1代表Hunan Agricultural University，2代表Jishou University，3代表Huaihua University，4代表Aerospace University，5代表Ocean University。
请编写程序根据考生的账号区分考生的学校。

输入格式:
在一行中给出1个6位的正整数account。

输出格式:
在一行中输出account的学校。注意：如果不清楚学校代号是哪个学校，则输出"OtherUniversity"。

输入样例:
123456

输出样例:
Hunan Agricultural University

***********************************/

#include <stdio.h>

int main() {
    int input;

    scanf("%d", &input);

    int school = input / 100000;

    switch(school) {
        case 1:
            printf("Hunan Agricultural University");
            break;
        case 2:
            printf("Jishou University");
            break;
        case 3:
            printf("Huaihua University");
            break;
        case 4:
            printf("Aerospace University");
            break;
        case 5:
            printf("Ocean University");
            break;
        default:
            printf("Other University");
            break;
    }

return 0;
}