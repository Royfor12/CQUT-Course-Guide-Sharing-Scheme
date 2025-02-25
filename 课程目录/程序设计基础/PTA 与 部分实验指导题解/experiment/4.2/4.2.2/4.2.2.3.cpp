#include <stdio.h>
int main() {

    int a = 3;
    
    printf("%d\n", a + (a -= a * a));

return 0;
} 