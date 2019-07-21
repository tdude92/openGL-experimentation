VPATH = ../include/SFML ../include/GL ../include

opengl: main.o
	g++ -Wall main.o -o main -L../lib -lopengl32 -L../lib/sfml -lsfml-graphics -lsfml-window -lsfml-system -L../lib/glew -llibglew32 

main.o: main.cpp Window.hpp
	g++ -c main.cpp -I ../include

clean:
	del /S main.o main.exe