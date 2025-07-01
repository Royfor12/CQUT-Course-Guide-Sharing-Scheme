#include <stdio.h>

int generateStateNum(int a, int state)
{
    int sum = 0;
    int ret = 1;

    for (int i = 1; i <= state; i++) {
        sum += a * ret;

        ret *= 10;
    }

    return sum;
}

int func(int a, int state)
{
    int sum = 0;

    for (int i = 1; i <= state; i++) {
        sum += generateStateNum(a, i);
    }

    return sum;
}

int main(void)
{
    int a, state;
    __attribute__((unused)) int ret = scanf("%d%d", &a, &state);

    printf("%d\n", func(a, state));

    return 0;
}