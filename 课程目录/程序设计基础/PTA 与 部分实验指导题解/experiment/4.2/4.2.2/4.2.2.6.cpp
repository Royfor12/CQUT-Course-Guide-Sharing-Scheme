#include <stdio.h>
int main() {

    int a, b, x, y;

    a = 2.0, b = 3.0, x = 3.5, y = 2.5;
    
    printf("result 1 = %f\n", ((float)(a + b)) / 2.0 + (int)x % (int)y);
    printf("result 2 = %f\n", (float)(a + b / 2.0) + (int)x % (int)y);
    printf("result 3 = %f\n", (float)(a + b / 2.0) + (int)x % (int)y);
    
return 0;
}