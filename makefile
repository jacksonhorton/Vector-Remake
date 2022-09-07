TARGET=main
CC=g++
CFLAGS=-g -Wall -Wextra
TEST=valgrind --leak-check=yes --track-origins=yes -v

main: Vector.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: Vector.cpp main.cpp
	$(CC)  $(CFLAGS) -c main.cpp

main.cpp: Vector.cpp

Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) -c Vector.cpp

rebuild:
	$(MAKE) clean
	$(MAKE) $(TARGET)

test:
	$(TEST) ./$(TARGET)

clean:
	$(RM) dyn *.o *~ *# $(TARGET)
