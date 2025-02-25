#include <stdio.h>
int main() {

    int i,m,n;

    i = 5;

    printf("before i++ i=%d\n", i);

    m = i++;

    printf("after i++ i=%d\n", i);

    n = ++i;
    
    printf("after ++i i=%d m=%d n=%d\n", i, m, n);

return 0;
}