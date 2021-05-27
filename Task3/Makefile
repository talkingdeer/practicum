CC = g++
CFLAGS = -Wall

task: main.cpp Circle.o Square.o Triangle.o Exeption.o Square_Circle.o
	$(CC) $(CFLAGS) -o task main.cpp Circle.o Square.o Triangle.o Exeption.o Square_Circle.o

%.c : %.h

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

run:
	./task

clean:
	rm task Circle.o Square.o Triangle.o Square_Circle.o Exeption.o
