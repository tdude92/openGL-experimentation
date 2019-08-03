FILE = transformations
VPATH = ../include/SFML ../include/GL ../include/glm ../include/glm/gtc ../include

main: $(FILE).o stb_image.o
	g++ -Wall $(FILE).o stb_image.o -o main -L../lib -lopengl32 -L../lib/sfml -lsfml-graphics -lsfml-window -lsfml-system -L../lib/glew -lglew32 

$(FILE).o: $(FILE).cpp Window.hpp glew.h shaders.hpp stb_image.h glm.hpp matrix_transform.hpp type_ptr.hpp
	g++ -c $(FILE).cpp -I ../include

stb_image.o: stb_image.cpp stb_image.h
	g++ -c stb_image.cpp -I ../include

clean:
	del /S $(FILE).o stb_image.o main.exe 