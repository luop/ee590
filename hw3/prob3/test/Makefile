CXX = g++ -std=c++11
LIBS = -lm
INCLUDE_DIRS = -I..

FRACTION_LIBS = -lm -lfraction
FRACTION_DIRS = -I.. -I../../prob1
FRACTION_LIBDIRS = -L../../prob1

COMPLEX_LIBS = -lm -lComplexNum
COMPLEX_DIRS = -I.. -I../../prob2
COMPLEX_LIBDIRS = -L../../prob2

SOURCES = 1.cc 2.cc 3.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS) fraction complex

%.x: %.cc ../*.hh
	$(CXX) $(LIBS) $(INCLUDE_DIRS) $< -o $@

fraction: 4.cc ../*.hh
	$(CXX) $(FRACTION_DIRS) $(FRACTION_LIBDIRS) $< -o 4.x $(FRACTION_LIBS)

complex: 5.cc ../*.hh
	$(CXX) $(COMPLEX_DIRS) $(COMPLEX_LIBDIRS) $< -o 5.x $(COMPLEX_LIBS)

test: $(TARGETS) fraction complex
	./test.sh

clean:
	rm -rf $(TARGETS) 4.x 5.x
