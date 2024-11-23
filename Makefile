include_path = "lib/SFML-2.6.1/include"
link_path = "lib/SFML-2.6.1/lib"
cpp_files_path = src/classes/
obj_files_path = bin/
hpp_files_path = src/include

all: compile link

compile:
	@for %%f in ($(cpp_files_path)*.cpp) do ( \
		g++ -c $(cpp_files_path)%%~nxf -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)%%~nf.o \
	)

link:
	g++ -o $(obj_files_path)app.exe $(obj_files_path)*.o -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system

run:
	$(obj_files_path)app.exe

clean:
	if exist "bin\app.exe" del "bin\app.exe"
	if exist "bin\*.o" del "bin\*.o"
