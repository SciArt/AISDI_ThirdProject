all: main.cpp App.cpp Graph.cpp
	g++ -std=c++11 -o app main.cpp App.cpp Graph.cpp

clean:
	rm -f *.o

