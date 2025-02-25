#include <stdio.h>

int main() {
    double U = 220;
    double R1 = 10000;
    double R2 = 10000;
    double R3 = 200000;
    double R4 = 200000;

    double I1 = U / R1;
    double I2 = U / R2;
    double I3 = U / R3;
    double I4 = U / R4;

    double total_r = (1 / R1) + (1 / R2) + (1 / R3) + (1 / R4);
    double r = 1 / total_r;

    printf("R1 = %.6lf A\n", I1);
    printf("R2 = %.6lf A\n", I2);
    printf("R3 = %.6lf A\n", I3);
    printf("R4 = %.6lf A\n", I4);
    printf("r = %.6lf Ω\n", r);

return 0;
}