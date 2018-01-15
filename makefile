all: main.cpp App.cpp Graph.cpp
	g++ -o app main.cpp App.cpp Graph.cpp

clean:
	rm -f *.o

