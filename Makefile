include_path = "./lib/SFML-2.6.1/include"
link_path = "./lib/SFML-2.6.1/lib"
cpp_files_path = ./src/classes/
obj_files_path = ./bin/

all:compile
compile: 
	for file in $(cpp_files_path)*; do \
        g++ -c $$file -I $(include_path) -o $(obj_files_path)$$(basename $$file).o; \
    done

link:
	g++ $(obj_files_path)* -o app.exe -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app.exe

clean:
	rm -rf app.exe $(obj_files_path)*

# g++ -c $(cpp_files_path)snake.cpp -I $(include_path) -o $(obj_files_path)snake.o
# g++ $(obj_files_path)snake.o -o app.exe -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system