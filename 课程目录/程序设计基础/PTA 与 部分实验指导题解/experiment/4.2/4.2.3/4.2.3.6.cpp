#include <stdio.h>

int main() {
    double mass_per_fenzi = 3e-23;
    double mass_per_quart = 950;

    double quarts;
    printf("输入水的夸脱数: ");
    scanf("%lf", &quarts);

    double total_mass = quarts * mass_per_quart;
    double fenzi_count = total_mass / mass_per_fenzi;

    printf("在%.2lf夸脱的水中包含大约 %.2e 个水分子。\n", quarts, fenzi_count);

return 0;
}
