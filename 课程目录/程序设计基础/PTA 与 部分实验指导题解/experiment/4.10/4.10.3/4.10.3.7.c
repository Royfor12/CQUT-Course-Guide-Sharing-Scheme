struct Employee {
    int id;
    float salary;
};

void sortEmployees(struct Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].id > employees[j + 1].id) {
                struct Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

#include <stdio.h>

#define max_employees 100

void sortEmployees(struct Employee employees[], int n);

int main() {
    struct Employee employees[max_employees];
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %f", &employees[i].id, &employees[i].salary);
    }

    sortEmployees(employees, n);

    for (int i = 0; i < n; i++) {
        printf("%d %.2f\n", employees[i].id, employees[i].salary);
    }

    return 0;
}