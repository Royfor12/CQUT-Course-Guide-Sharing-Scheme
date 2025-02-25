#include <stdio.h>
int main() {

    int a, n;

    a = 12, n = 5;
    
    printf("%d\n", a += a);
    printf("%d\n", a -= 2);
    printf("%d\n", a *= 2 + 3);
    printf("%d\n", a %= (n %= 2));
    printf("%d\n", a /= a + a);
    printf("%d\n", a + a - a * a);
    
return 0;
}