#include <stdio.h>
int main() {
    int a, k;
    scanf("%d", &a);
    if (a > 0) {
        printf("%d:", a);
        for (int k = a; k > 0; k--) {
            if (a % k == 0) {
                printf(" %d", k);
            }
        }
        printf("\n");
    }
return 0;
}