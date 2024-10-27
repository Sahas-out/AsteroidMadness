include_path = "./lib/SFML-2.6.1/include"
link_path = "./lib/SFML-2.6.1/lib"
cpp_files_path = ./src/classes/
obj_files_path = ./bin/
all:compile
compile:
	g++ -c $(cpp_files_path)test.cpp -I $(include_path) -o $(obj_files_path)test.o

link:
	g++ $(obj_files_path)test.o -o app.exe -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app.exe

clean:
	rm -rf app.exe $(obj_files_path)*