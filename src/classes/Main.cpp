#include<iostream>
#include "Game.hpp"
#include<fstream>
int main()
{   
        Game* game = new Game();
        game->run();
        delete game;
        return 0;
}
