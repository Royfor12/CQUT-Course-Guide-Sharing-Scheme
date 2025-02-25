#include <stdio.h>
int main() {
    int a, b, c;

    printf("input three integers:");

    scanf("%d %d %d", &a, &b, &c);

    int result = a * 100 + b * 10 + c;

    printf("result is: %d\n", result);

return 0;
}