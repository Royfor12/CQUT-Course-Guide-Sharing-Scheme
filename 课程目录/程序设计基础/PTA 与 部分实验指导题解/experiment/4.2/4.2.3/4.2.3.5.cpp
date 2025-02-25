#include <stdio.h>

int main() {
    float v0 = 10.0;
    float a = 2.0;
    float t = 20.0;
    
    float v = v0 + a * t;
    float s = v0 * t + 0.5 * a * t * t;
    float v_avg = s / t;
    
    printf("20秒后的速度为: %.2f m/s\n", v);
    printf("20秒内走过的路程为: %.2f m\n", s);
    printf("20秒内的平均速度为: %.2f m/s\n", v_avg);
    
return 0;
}
