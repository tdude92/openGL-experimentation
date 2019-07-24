FILE = hellotriangle-problems
VPATH = ../include/SFML ../include/GL ../include

main: $(FILE).o
	g++ -Wall $(FILE).o -o main -L../lib -lopengl32 -L../lib/sfml -lsfml-graphics -lsfml-window -lsfml-system -L../lib/glew -llibglew32 

$(FILE).o: $(FILE).cpp Window.hpp
	g++ -c $(FILE).cpp -I ../include

clean:
	del /S $(FILE).o main.exe