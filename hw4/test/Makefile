CXX = g++ -std=c++11 -O3
LIBS = -ljson
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 2.cc 3.cc 4.cc 5.cc 6.cc 7.cc 8.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libjson.a
	$(CXX) $(INCLUDE_DIRS) $(LIBDIRS) $< $(LIBS) -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
