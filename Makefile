include_path = "lib/SFML-2.6.1/include"
link_path = "lib/SFML-2.6.1/lib"
cpp_files_path = src/classes/
obj_files_path = bin/
all:compile link
compile:
	g++ -c $(cpp_files_path)Shooter.cpp -I $(include_path) -o $(obj_files_path)Shooter.o
	g++ -c $(cpp_files_path)main.cpp -I $(include_path) -o $(obj_files_path)main.o

link:
	g++ $(obj_files_path)Shooter.o $(obj_files_path)main.o -o $(obj_files_path)app.exe -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system

run:
	$(obj_files_path)app.exe

clean:
	del app.exe $(obj_files_path)*