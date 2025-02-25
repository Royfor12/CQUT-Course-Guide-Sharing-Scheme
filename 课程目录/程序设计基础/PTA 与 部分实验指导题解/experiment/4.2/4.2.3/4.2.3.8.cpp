#include <stdio.h>
#define PI 3.1416  // 定义圆周率

int main() {
    double r = 1.5;
    double h = 3.0;

    double circumference = 2 * PI * r;

    double surface_area = 2 * PI * r * (r + h);

    double volume = PI * r * r * h;

    printf("圆柱的底面周长为: %.2lf\n", circumference);
    printf("圆柱的表面积为: %.2lf\n", surface_area);
    printf("圆柱的体积为: %.2lf\n", volume);

return 0;
}