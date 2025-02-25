struct Car {
    int number;
    int drive_miles;
    int gallonsConsumed;
};

#include <stdio.h>

double calculate(int miles, int gallons) {
    return (double)gallons / (miles / 100);
}

int main() {
    struct Car cars[5];

    for (int i = 0; i < 5; i++) {
        scanf("%d %d %d", &cars[i].number, &cars[i].drive_miles, &cars[i].gallonsConsumed);
    }

    for (int i = 0; i < 5; i++) {
        double result = calculate(cars[i].drive_miles, cars[i].gallonsConsumed);
        printf("Car %d: %.2lf gallons per 100 miles\n", cars[i].number, result);
    }
    return 0;
}