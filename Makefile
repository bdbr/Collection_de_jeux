CPP=g++ --std=c++11
CFLAGS  = -Wall 
EXEC = Jeux

HEADERS = $(wildcard *.h)
OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))


all: $(EXEC)


Jeux: $(OBJECTS)
	$(CPP) -o $@ $^ $(CFLAGS)

%.o: %.cpp $(HEADERS)
	$(CPP) -c -o $@ $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f $(EXEC)
