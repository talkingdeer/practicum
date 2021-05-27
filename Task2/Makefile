CC = g++
CFLAGS = -Wall

task: main.cpp List.o Exeption.o
	$(CC) $(CFLAGS) -o task main.cpp List.o Exeption.o

%.c : %.h

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

run:
	./task

clean:
	rm task List.o Exeption.o
