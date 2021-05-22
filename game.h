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
    int gameMode;
    int numberOfMoves;

    void gameOver();
    void printInitialMessage();
    void chooseGameMode();
    void newTable();
    void action();
};
#endif