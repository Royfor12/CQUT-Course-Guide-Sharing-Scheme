#include <stdio.h>
int main() {

    int num, a = 0;

    printf("input: ");

    scanf("%d", &num);

    while (num != 0) {
    a = a * 10 + num % 10;
    num = num / 10;
    }
    
    printf("result is: %d\n", a);

return 0;
}