CC = g++
CFLAGS = -g -I include/
SRCDIR = .\src
SRC_C = $(wildcard $(addsuffix /*.c, $(SRCDIR)))
OBJ = main.cpp helper.cpp src\User.cpp src\StreamingService.cpp src\UserDatabase.cpp

%.exe: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
	
main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

run: main
	./main

clean:
	find . -name "*.o" -type f -delete