#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/wait.h>

#define FILE_NAME "test.txt"

int main(void)
{
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error: failed to fork!\n");
        return 1;
    }

    if (pid == 0) {
        printf("Sub process start.\n");
        sleep(10);

        if (access(FILE_NAME, 0) != 0) {
            printf("Error: file " FILE_NAME "does not exist!\n");
            return 1;
        }

        FILE *stream = fopen(FILE_NAME, "r");
        if (stream == NULL) {
            printf("Error: Failed to open file " FILE_NAME "!\n");
            return 1;
        }

        char buffer[100];
        size_t index = 0U;
        do {
            __attribute__((unused)) int ret = fscanf(stream, "%c", &buffer[index]);
            index++;
        } while(buffer[index - 1] != EOF);

        printf("%s\n", buffer);

        fclose(stream);
    }
    else {
        printf("Sub process pid=%d\n", pid);
        int status;
        wait(&status);
    }

    return 0;
}
