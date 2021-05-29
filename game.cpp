#include "game.h"
#include <iostream>
using namespace std;

Game::Game()
{
    numberOfMoves = 0;
    isGameOver = false;
}

void Game::start()
{
    this->printInitialMessage();
    this->chooseGameMode();
    this->newTable();
    this->pTable->printTable();

    this->action();
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
}

void Game::action()
{
    char move;

    //Coordinates
    char alphabet;
    int number;

    while (!isGameOver)
    {
        cout << "Enter (MOVE, ALPHABET, NUMBER)" << endl;
        cout << "(MOVE = [f], Flag or [e], Explore)" << endl;

        cin >> move >> alphabet >> number;

        if (isValidMove(move, alphabet, number))
        {
            int i = number - 1;
            int j = int(alphabet) - 97;

            if (!this->pTable->pArray[i][j].getIsRevealed())
            {
                if (move == 'e') //Explore.
                {
                    this->explore(i, j);
                }
                else if (move == 'f') //Flag.
                {
                    this->pTable->pArray[i][j].flag();
                }
                numberOfMoves++;
            }
            this->pTable->printTable();
        }
        else
        {
            cout << "Invalid move!" << endl;
            continue;
        }
    }
    cout << "GAME OVER!";
    this->pTable->printTable();
}

void Game::gameOver()
{
    this->isGameOver = true;
}

void Game::newTable()
{

    switch (this->gameMode)
    {
    case 1:
    case 2:
    case 3:
        pTable = new Table(this->gameMode);
        break;

    case 4: //Customization.
        int tableSize, numberOfMines;

        cout << endl;

        do
        {
            cout << "enter table size: (9 ~ 20)" << endl;
            cin >> tableSize;
        } while (!(tableSize >= 9 && tableSize <= 20));

        do
        {
            cout << "Enter number of mine: (1 ~ " << (tableSize - 1) * (tableSize - 1) << ")" << endl;
            cin >> numberOfMines;
        } while (numberOfMines < 1 || numberOfMines > (tableSize - 1) * (tableSize - 1));

        pTable = new Table(tableSize, numberOfMines);

        break;

    default:
        pTable = new Table();
        break;
    }
}

bool Game::isValidMove(char move, char alphabet, int number)
{
    return !((move != 'e' && move != 'f') || (int(alphabet) - 96 < 1 || int(alphabet) - 96 > this->pTable->tableSize) || (number < 1 || number > this->pTable->tableSize));
}

void Game::explore(int i, int j)
{
    if (!this->pTable->pArray[i][j].isMine())
    {
        this->pTable->chainReveal(i, j);
    }
    else //This is mine.
    {
        if (numberOfMoves == 0) // First step mercy.
        {
            this->pTable->replantThisMine(i, j);
            this->explore(i, j);
        }
        else
        {
            this->gameOver();
            this->pTable->revealAllMines();
        }
    }
}