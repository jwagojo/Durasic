CC = g++
CFLAGS = --std=c++20 -Wall -Werror -pedantic -g
# Your .hpp files
DEPS = sSort.hpp
# Your compiled .o files
OBJECTS = sSort.o
# The name of your program
PROGRAM = sSort

.PHONY: all clean lint


all: $(PROGRAM)

# Wildcard recipe to make .o files from corresponding .cpp file
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(PROGRAM): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM)

lint:
	cpplint *.cpp *.hpp
