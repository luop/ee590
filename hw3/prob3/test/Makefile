CXX = g++ -std=c++11
LIBS = -lm -lfraction
INCLUDE_DIRS = -I.. -I../../prob1
LIBDIRS = -L../../prob1

SOURCES = 1.cc 2.cc 3.cc 4.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< -o $@ $(LIBS)

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
