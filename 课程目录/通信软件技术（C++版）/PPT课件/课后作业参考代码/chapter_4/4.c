#include <stdio.h>
#include <string.h>

#define countof(array) (sizeof(array) / sizeof(array[0]))

int main(void)
{
    char str[9999];
    __attribute__((unused)) char* dummy_ptr = fgets(str, countof(str), stdin);

    int upper = 0, lower = 0;

    for (int i = 0; i < strlen(str); i++) {
        const char ch = str[i];

        if (ch >= 'a' && ch <= 'z') {
            lower++;
        }
        if (ch >= 'A' && ch <= 'Z') {
            upper++;
        }
    }

    printf("Upper: %d, Lower: %d\n", upper, lower);

    return 0;
}
