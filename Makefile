# Paths
include_path = -I./lib/SFML-2.5.1/include -I./src/include -I./src/classes
link_path = ./lib/SFML-2.5.1/lib
cpp_files_path = ./src/classes/
obj_files_path = ./bin/

# Target for all steps
all: compile link run clean

# Compile step
compile:
	g++ -c $(cpp_files_path)main.cpp $(include_path) -o $(obj_files_path)main.o
	g++ -c $(cpp_files_path)Game.cpp $(include_path) -o $(obj_files_path)Game.o
	g++ -c $(cpp_files_path)Asteroid.cpp $(include_path) -o $(obj_files_path)Asteroid.o

# Link step
link:
	g++ $(obj_files_path)main.o $(obj_files_path)Game.o $(obj_files_path)Asteroid.o -o app.exe -L $(link_path) -lsfml-system -lsfml-window -lsfml-graphics

# Run step
run:
	export PATH=./lib/SFML-2.5.1/bin:$$PATH && ./app.exe

# Clean step
clean:
	rm -rf app.exe $(obj_files_path)*.o
