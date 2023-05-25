all: clean compile link run

compile:
	g++ -c main.cpp game.cpp sky.cpp ground.cpp pipe.cpp pipe_manager.cpp start_screen.cpp bird.cpp -I"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ main.o game.o sky.o ground.o pipe.o pipe_manager.o start_screen.o bird.o -o main -L"C:\SFML-2.5.1-windows-gcc-7.3.0-mingw-64-bit\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

run:
	.\main

clean:
	rm -f main *.o