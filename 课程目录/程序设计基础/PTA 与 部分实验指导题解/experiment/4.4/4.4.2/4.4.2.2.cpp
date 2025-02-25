#include <stdio.h>

int main() {
    int numbers[10];
    int max;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }

    max = numbers[0];

    for (int i = 1; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("max: %d\n", max);

return 0;
}
