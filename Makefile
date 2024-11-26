# Paths
<<<<<<< Updated upstream
include_path = -I./lib/SFML-2.5.1/include -I./src/include -I./src/classes
link_path = ./lib/SFML-2.5.1/lib
=======
include_path = -I./lib/SFML-2.6.2/include -I./src/include -I./src/classes
link_path = ./lib/SFML-2.6.2/lib
>>>>>>> Stashed changes
cpp_files_path = ./src/classes/
obj_files_path = ./bin/

# Source files and object files
CPP_FILES = $(wildcard $(cpp_files_path)*.cpp)
OBJ_FILES = $(patsubst $(cpp_files_path)%.cpp, $(obj_files_path)%.o, $(CPP_FILES))

# Target for all steps
all: compile link run clean

# Compile step
compile: $(OBJ_FILES)

$(obj_files_path)%.o: $(cpp_files_path)%.cpp
	g++ -c $< $(include_path) -o $@

# Link step
link:
<<<<<<< Updated upstream
	g++ $(OBJ_FILES) -o app.exe -L $(link_path) -lsfml-system -lsfml-window -lsfml-graphics

# Run step
run:
	export PATH=./lib/SFML-2.5.1/bin:$$PATH && ./app.exe
=======
	g++ $(OBJ_FILES) -o app.exe -L $(link_path) -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

# Run step
run:
	export PATH=./lib/SFML-2.6.2/bin:$$PATH && ./app.exe
>>>>>>> Stashed changes

# Clean step
clean:
	rm -rf app.exe $(obj_files_path)*.o
