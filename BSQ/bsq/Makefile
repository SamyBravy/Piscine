# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Name of the executable
PROG = rush-BSQ

# List of object files
OBJS = main.o handleinput.o fileman.o string.o userinput.o solve.o

# Default target
all: $(PROG)

# Linking the final program from the object files
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiling the source files into object files
main.o: main.c handleinput.h fileman.h solve.h
	$(CC) $(CFLAGS) -c $<

handleinput.o: handleinput.c handleinput.h fileman.h userinput.h
	$(CC) $(CFLAGS) -c $<

fileman.o: fileman.c fileman.h string.h
	$(CC) $(CFLAGS) -c $<

string.o: string.c string.h
	$(CC) $(CFLAGS) -c $<

userinput.o: userinput.c userinput.h fileman.h string.h
	$(CC) $(CFLAGS) -c $<

solve.o: solve.c solve.h fileman.h
	$(CC) $(CFLAGS) -c $<

# Clean target
fclean:
	rm -f $(PROG) $(OBJS)
