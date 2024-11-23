include_path = "lib/SFML-2.6.1/include"
link_path = "lib/SFML-2.6.1/lib"
cpp_files_path = src/classes/
obj_files_path = bin/
hpp_files_path = src/include
all:compile 
compile:
	@for file in $(cpp_files_path)*; do \
		g++ -g -c $$file -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)$$(basename $$file .cpp).o; \
	done 
link:
	g++ -o $(obj_files_path)app.exe $(obj_files_path)*  -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system

run:
	$(obj_files_path)app.exe

clean:
	rm -rf $(obj_files_path)app.exe $(obj_files_path)*