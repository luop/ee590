CXX = g++ -std=c++11 -O3
LIBS = -lm -lfraction
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cpp 2.cpp 3.cpp 4.cpp
TARGETS = $(SOURCES:%.cpp=%.x)

all: $(TARGETS)

%.x: %.cpp ../libfraction.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< -o $@ $(LIBS)

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
