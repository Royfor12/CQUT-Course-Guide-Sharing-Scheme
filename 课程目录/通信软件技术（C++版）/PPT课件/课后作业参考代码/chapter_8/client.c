#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "fifo_def.h"

#define TX_FIFO_NAME "client_to_server"
#define RX_FIFO_NAME "server_to_client"

int main(void)
{
    if (access(FIFO_DIR, F_OK) != 0) {
        printf("Fifo dir not exists, now crerate it.\n");
        __attribute__((unused)) int ret = system("mkdir " FIFO_DIR);
    }

    int err = mkfifo(FIFO_DIR TX_FIFO_NAME, 0666);
    if (err == -1) {
        fprintf(stderr, "Failed to create fifo " TX_FIFO_NAME "! Error Code: %d\n", err);
        return 1;
    }
    printf("finished to create fifo " TX_FIFO_NAME ".\n");

    printf("waitting for " RX_FIFO_NAME "...\n");
    while (access(FIFO_DIR RX_FIFO_NAME, F_OK) != 0) {
    }
    printf(RX_FIFO_NAME " created.\n");

    int rx_fifo = open(FIFO_DIR RX_FIFO_NAME, O_RDONLY);
    if (rx_fifo == -1) {
        fprintf(stderr, "Failed to open fifo " RX_FIFO_NAME "! ErrorCode: %d\n", rx_fifo);
        unlink(FIFO_DIR TX_FIFO_NAME);
        return 1;
    }
    printf("Fininshed to open fifo " RX_FIFO_NAME ".\n");

    int tx_fifo = open(FIFO_DIR TX_FIFO_NAME, O_WRONLY);
    if (tx_fifo == -1) {
        fprintf(stderr, "Failed to open fifo " TX_FIFO_NAME "! ErrorCode: %d\n", tx_fifo);
        unlink(FIFO_DIR TX_FIFO_NAME);
        close(rx_fifo);
        return 1;
    }
    printf("Finished to open fifo " TX_FIFO_NAME ".\n");

    char rx_buffer[256], tx_buffer[256];
    while (true) {
        int size = read(rx_fifo, rx_buffer, sizeof rx_buffer / sizeof rx_buffer[0] - 1);
        rx_buffer[size] = '\0';
        printf("Readden buffer: %s, size = %d\n", rx_buffer, size);

        if (strcmp(rx_buffer, "esc") == 0) {
            break;
        }

        printf("Input message: ");
        fflush(stdin);
        __attribute__((unused)) int ret = scanf("%s", tx_buffer);
        size = write(tx_fifo, tx_buffer, strlen(tx_buffer));
        printf("Written buffer: %s, size = %d\n", tx_buffer, size);

        if (strcmp(tx_buffer, "esc") == 0) {
            break;
        }
    }

    close(rx_fifo);
    close(tx_fifo);
    unlink(FIFO_DIR TX_FIFO_NAME);

    return 0;
}