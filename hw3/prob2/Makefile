CXX = g++ -std=c++11 -O3

SOURCES = ComplexNum.cpp ComplexNumOp.cpp
HEADERS = ComplexNum.h

OBJECTS=$(SOURCES:.cpp=.o)

LIB_COMPLEXNUM=libComplexNum.a

all: $(LIB_COMPLEXNUM)
	make -C test

$(LIB_COMPLEXNUM): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_COMPLEXNUM) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_COMPLEXNUM)
	make -C test clean
