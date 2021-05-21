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
    this->pTable->printTable();
    while (!isGameOver)
    {
        this->action();
        if (this->isGameOver)
            cout << "遊戲已結束!!";
        this->pTable->printTable();
    }
}

void Game::printInitialMessage()
{
    cout << "選擇你所要玩的模式:" << endl;//選擇難度
    cout << "1. 初階" << endl;//難度一
    cout << "2. 中階" << endl;//難度二
    cout << "3. 困難" << endl;//難度三
    cout << "4. 自訂遊戲" << endl;//客製化遊戲
}

void Game::chooseGameMode()
{
    int gameMode;
    cin >> gameMode;
    this->gameMode = gameMode;

    //遊戲模式1、2、3、4
    if (this->gameMode == 1 || this->gameMode == 2 || this->gameMode == 3)
        pTable = new Table(this->gameMode);

    //客製難度
    else if (this->gameMode == 4)
    {
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
    }

    //選擇其他的話就是預設的模式.
    else
        pTable = new Table();

}

void Game::action()
{
    char move;

    char alphabat;
    int number;

    cout << "輸入:(動作, 座標的字母, 座標的數字)" << endl;//輸入動作、字母、數字
    cout << "(動作 = [f]做標記 or [e]動作踩)" << endl;//f是做標記，e是動作踩

    cin >> move >> alphabat >> number;

    int i = number - 1;
    int j = int(alphabat) - 97;

    if ((move == 'e' || move == 'f'))
        if (this->pTable->isValid(i, j))
        {
            if (!this->pTable->pArray[i][j].getIsRevealed())
            {
                if (move == 'e') //動作踩
                {
                    if (!this->pTable->pArray[i][j].isMine())
                    {
                        this->pTable->chainReveal(i, j);
                    }
                    else //這是地雷.
                    {
                        if (numberOfMoves == 0) // 如果第一下踩到地雷，這顆地雷會移到別處。
                        {
                        }
                        else
                        {
                            this->gameOver();
                            this->pTable->revealAllMines();
                        }
                    }
                }
                else if (move == 'f') //如果動作"f"是放旗標
                {
                    this->pTable->pArray[i][j].flag();
                }
                numberOfMoves++;
            }
        }
}

void Game::gameOver()
{
    this->isGameOver = true;
}