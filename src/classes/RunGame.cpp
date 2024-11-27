#include"GameRunner.h"
#include"Game.h"
JNIEXPORT jint JNICALL Java_GameRunner_runGame
(JNIEnv *, jobject)
{
    Game* game = new Game();
    game->run();
    delete game;
    return game->getSessionHighScore();
}