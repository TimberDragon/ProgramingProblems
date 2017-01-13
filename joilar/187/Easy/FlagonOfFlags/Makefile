
PROG := main
COMPILER := g++
CXXFLAGS := -g -Wall -O2 -pipe -std=c++11

all: $(PROG).exe

$(PROG).exe: $(PROG).cpp
	$(COMPILER) $(CXXFLAGS) -o $(PROG).exe $(PROG).cpp

clean:
	rm -v $(PROG).exe
