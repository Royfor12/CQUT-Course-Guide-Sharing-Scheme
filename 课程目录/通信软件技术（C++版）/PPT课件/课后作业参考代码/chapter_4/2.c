#include <stdio.h>
#include <stdint.h>

typedef struct Calc {
    size_t states;
    size_t now_state;

    double sum;
} Calc;

double func(Calc* calc, int a, int b)
{
    if (calc->now_state >= calc->states) {
        return 0.0;
    }

    calc->now_state++;
    calc->sum += (double)a / (double)b + func(calc, b, a + b);
}

int main(void)
{
    int n;

    __attribute__((unused)) int ret = scanf("%d", &n);

    Calc ans = {0};
    ans.states = n;

    func(&ans, 1, 1);

    printf("%lf\n", ans.sum);

    return 0;
}
