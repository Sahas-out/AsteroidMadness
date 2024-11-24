include_path = "lib/SFML-2.6.1/include"
link_path = "lib/SFML-2.6.1/lib"
cpp_files_path = src/classes/
obj_files_path = bin/
hpp_files_path = src/include
all: compile link
# compile:
# 	@for file in $(cpp_files_path)*; do \
# 		g++ -g -c $$file -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)$$(basename $$file .cpp).o; \
# 	done 
compile: Main.o
	echo compilation complete

link: compile
	g++ -o $(obj_files_path)app.exe $(obj_files_path)*  -L $(link_path) -lsfml-graphics -lsfml-window -lsfml-system
	echo linked succesfully

run:
	$(obj_files_path)app.exe

clean:
	rm -rf $(obj_files_path)app.exe 
# $(obj_files_path)*

GameUtils.o:
	g++ -g -c $(cpp_files_path)GameUtils.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)GameUtils.o

Missile.o: GameUtils.o
	g++ -g -c $(cpp_files_path)Missile.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)Missile.o

Shooter.o: Missile.o
	g++ -g -c $(cpp_files_path)Shooter.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)Shooter.o

MissileManager.o: Missile.o
	g++ -g -c $(cpp_files_path)MissileManager.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)MissileManager.o

ShooterManager.o: Shooter.o
	g++ -g -c $(cpp_files_path)ShooterManager.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)ShooterManager.o

Asteroid.o:
	g++ -g -c $(cpp_files_path)Asteroid.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)Asteroid.o
	
AsteroidManager.o: Asteroid.o
	g++ -g -c $(cpp_files_path)AsteroidManager.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)AsteroidManager.o

Game.o : MissileManager.o AsteroidManager.o ShooterManager.o
	g++ -g -c $(cpp_files_path)Game.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)Game.o

Main.o : Game.o
	g++ -g -c $(cpp_files_path)Main.cpp -I $(include_path) -I $(hpp_files_path) -o $(obj_files_path)Main.o

