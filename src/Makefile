CXX = g++
VPATH = ../include/SFML ../include/GL

opengl: main.o
	g++ main.o -o opengl -L ../lib/sfml -l sfml-graphics -l sfml-window -l sfml-system -L ../lib/glew -l libglew32

main.o: main.cpp Window.hpp
	g++ -c main.cpp -I ../include

clean:
	del /S main.o opengl.exe