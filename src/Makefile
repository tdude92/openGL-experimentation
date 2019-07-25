FILE = textures
VPATH = ../include/SFML ../include/GL ../include

main: $(FILE).o stb_image.o
	g++ -Wall $(FILE).o stb_image.o -o main -L../lib -lopengl32 -L../lib/sfml -lsfml-graphics -lsfml-window -lsfml-system -L../lib/glew -llibglew32 

$(FILE).o: $(FILE).cpp Window.hpp glew.h shaders.hpp stb_image.h filesystem.h
	g++ -c $(FILE).cpp -I ../include

stb_image.o: stb_image.cpp stb_image.h
	g++ -c stb_image.cpp -I ../include

clean:
	del /S $(FILE).o main.exe