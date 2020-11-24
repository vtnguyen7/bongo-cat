FLAGS = -lX11 -lncurses -I ~/bongo-cat/source/

bongocat: bongocat.o bongoWriter.o bongoConfig.o
	g++ $(FLAGS) bongocat.o bongoWriter.o bongoConfig.o -o bongocat

bongocat.o:  source/bongocat.cpp 
	g++ $(FLAGS) -c source/bongocat.cpp

bongoWriter.o: source/writer/bongoWriter.cpp source/writer/bongoWriter.h 
	g++ $(FLAGS) -c source/writer/bongoWriter.cpp

bongoConfig.o: source/config/bongoConfig.cpp source/config/bongoConfig.h source/config/bongoConstants.h
	g++ $(FLAGS) -c source/config/bongoConfig.cpp
