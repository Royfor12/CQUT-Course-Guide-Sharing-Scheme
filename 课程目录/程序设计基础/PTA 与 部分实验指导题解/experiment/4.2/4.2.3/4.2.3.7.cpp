#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;


    while (1) {  
        printf("请输入三角形的三条边 a, b, c: ");
        scanf("%lf %lf %lf", &a, &b, &c);

        if (a + b > c && a + c > b && b + c > a) {
            double s = (a + b + c) / 2;

            double area = sqrt(s * (s - a) * (s - b) * (s - c));

            printf("该三角形的面积为: %.2lf\n", area);

            break;
            } else {
                // 判断能否构成三角形
                while (getchar() != '\n');
                printf("输入的三条边不能构成一个三角形。\n");
        }
    }

return 0;
}
