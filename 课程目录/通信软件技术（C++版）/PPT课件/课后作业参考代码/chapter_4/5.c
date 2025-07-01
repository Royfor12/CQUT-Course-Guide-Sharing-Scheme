#include <stdio.h>
#include <string.h>

#define countof(array) (sizeof(array) / sizeof(array[0]))

char toUpper(char* ch)
{
    if (*ch >= 'a' && *ch <= 'z') {
        *ch -= 'a' - 'A';
    }
}

int main(void)
{
    char str[9999];
    __attribute__((unused)) char* dummy_ptr = fgets(str, countof(str), stdin);

    toUpper(&str[0]);

    const int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            toUpper(&str[i + 1]);
        }
    }

    printf("%s", str);

    return 0;
}
