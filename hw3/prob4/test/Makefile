CXX = g++ -std=c++11 -O3
LIBS = -lm -lDFT
INCLUDE_DIRS = -I..
LIBDIRS = -L..

COMPLEX_DIRS = -I../../prob2
MATRIX_DIRS = -I../../prob3

SOURCES = 1.cpp
TARGETS = $(SOURCES:%.cpp=%.x)

all: $(TARGETS)

%.x: %.cpp ../libDFT.a
	$(CXX) $(INCLUDE_DIRS) $(COMPLEX_DIRS) $(MATRIX_DIRS) $(LIBDIRS) $< -o $@ $(LIBS)

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
