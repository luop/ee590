CXX = g++ -std=c++11 -O3

SOURCES = fraction.cpp fraction_operations.cpp
HEADERS = fraction.h

OBJECTS=$(SOURCES:.cpp=.o)

LIB_FRACTION=libfraction.a

all: $(LIB_FRACTION)
	make -C test

$(LIB_FRACTION): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_FRACTION) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_FRACTION)
	make -C test clean
