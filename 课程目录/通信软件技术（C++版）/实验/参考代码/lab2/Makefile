CC = gcc

CFLAGS = -Wall -g -O3

TARGET = stu_manager

all:$(TARGET)

$(TARGET): main.o stu_manager.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o stu_manager.o
	
main.o: main.c stu_manager.h
	$(CC) $(CFLAGS) -c main.c
stu_manager.o: stu_manager.c stu_manager.h
	$(CC) $(CFLAGS) -c stu_manager.c

clean: rm -f $(TARGET) *.o

.PHONY: all clean