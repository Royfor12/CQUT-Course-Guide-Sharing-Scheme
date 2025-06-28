#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define FILE_NAME "test.txt"
#define MY_NAME   "your_name"
#define MY_ID     "12345678"

int main(void)
{
    if (access(FILE_NAME, 0) != 0) {
        if (system("touch " FILE_NAME) != 0) {
            printf("Error: failed to create file!");
            return 1;
        }
    }

    FILE* stream = fopen(FILE_NAME, "w");
    if (stream == NULL) {
        printf("Error: Failed to open file " FILE_NAME "!\n");
        return 1;
    }

    fprintf(stream, "Name: " MY_NAME "\n");
    fprintf(stream, "Id: " MY_ID "\n");
    fprintf(stream, "Time: ");

    time_t time_stamp;
    struct tm* time_info;
    time(&time_stamp);
    time_info = localtime(&time_stamp);

    const char* week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    const int year = time_info->tm_year + 1900;
    const int month = time_info->tm_mon + 1;
    const int day = time_info->tm_mday;
    const int week_num = time_info->tm_wday;
    const int hour = time_info->tm_hour;
    const int min = time_info->tm_min;
    const int sec = time_info->tm_sec;

    fprintf(stream, "%d/%d/%d %s %d:%d:%d\n", year, month, day, week[week_num], hour, min, sec);

    fclose(stream);

    return 0;
}
