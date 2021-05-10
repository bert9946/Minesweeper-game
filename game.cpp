#include "game.h"
#include <iostream>
using namespace std;

Game::Game()
{
    isGameOver = false;
}

void Game::start()
{
    this->printInitialMessage();
    this->chooseGameMode();
    pTable->printTable();
}

void Game::printInitialMessage()
{
    cout << "Choose Game Mode:" << endl;
    cout << "1 for Beginner" << endl;
    cout << "2 for Intermediate" << endl;
    cout << "3 for Advanced" << endl;
    cout << "4 for Customization" << endl;
}

void Game::chooseGameMode()
{
    int gameMode;
    cin >> gameMode;
    this->gameMode = gameMode;

    //game mode 1, 2, 3.
    if (this->gameMode == 1 || this->gameMode == 2 || this->gameMode == 3)
        pTable = new Table(this->gameMode);

    //game mode 4.
    else if (this->gameMode == 4)
    {
        int tableSize, numberOfMines;

        cout << endl;

        do
        {
            cout << "Enter table size: (9 ~ 20)" << endl;
            cin >> tableSize;
        } while (!(tableSize >= 9 && tableSize <= 20));

        do
        {
            cout << "Enter number of mine: (1 ~ " << (tableSize - 1) * (tableSize - 1) << ")" << endl;
            cin >> numberOfMines;
        } while (numberOfMines < 1 || numberOfMines > (tableSize - 1) * (tableSize - 1));

        pTable = new Table(tableSize, numberOfMines);
    }

    //game mode 1.
    else
        pTable = new Table();
}