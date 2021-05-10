#ifndef GAME_H
#define GAME_H
#include "table.h"
class Game
{

public:
    Game();
    void start();

private:
    Table *pTable;
    bool isGameOver;
    void printInitialMessage();
    int gameMode;
    void chooseGameMode();
};
#endif