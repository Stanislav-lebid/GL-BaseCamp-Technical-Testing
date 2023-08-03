CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LIB_NAME = libsearch.a

all: $(LIB_NAME) main

$(LIB_NAME): search_lib.o
    ar rcs $(LIB_NAME) search_lib.o

search_lib.o: search_lib.cpp search_lib.h
    $(CXX) $(CXXFLAGS) -c search_lib.cpp

main: main.cpp $(LIB_NAME)
    $(CXX) $(CXXFLAGS) -o main main.cpp -L. -lsearch -pthread

clean:
    rm -f *.o *.a main
