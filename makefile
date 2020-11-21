FLAGS = -lX11 -lncurses

bongocat: source/bongocat.o
	g++ $(FLAGS) source/bongocat.o -o bongocat

bongocat.o: source/bongocat.cpp
	g++ -c bongocat.cpp
