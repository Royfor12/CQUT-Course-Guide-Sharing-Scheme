#include <stdio.h>
int main() {

    char c1, c2;

    c1 = 97;
    c2 = 98;

    printf("c1=%c, c2=%c\n", c1, c2);
    printf("c1=%d, c2=%d\n", c1, c2);

    c1 = c1 - 32;
    c2 = c2 - 32;

    printf("c1=%c, c2=%c\n", c1, c2);
    printf("c1=%d, c2=%d\n", c1, c2);

getchar();

return 0;
}