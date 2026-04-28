INCLUDE= ./include
SRC= ./src
OBJS=main.o

main: $(OBJS)
	gcc -o main $(OBJS)

