CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -O3 -march=native
all: build run
build: main
run: level_output.adofai
main: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<
level_output.adofai: main level.adofai
	./main
clean:
	rm -f main level_output.adofai backup.adofai
.PHONY: all build run clean
