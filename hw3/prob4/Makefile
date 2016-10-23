CXX = g++ -std=c++11 -O3

SOURCES = DFT.cpp
HEADERS = DFT.h

OBJECTS=$(SOURCES:.cpp=.o)

LIB_DFT=libDFT.a

all: $(LIB_DFT)
	make -C test

$(LIB_DFT): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_DFT) $(OBJECTS) ../prob2/ComplexNum.o ../prob2/ComplexNumOp.o

%.o: %.cpp $(HEADERS)
	$(CXX) -c -I../prob3/ -I../prob2/ $<

clean:
	rm -f $(OBJECTS) $(LIB_DFT)
	make -C test clean
