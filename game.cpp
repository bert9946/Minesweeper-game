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
            cout << "�C���w����!!";
        this->pTable->printTable();
    }
}

void Game::printInitialMessage()
{
    cout << "��ܧA�ҭn�����Ҧ�:" << endl;//�������
    cout << "1. �춥" << endl;//���פ@
    cout << "2. ����" << endl;//���פG
    cout << "3. �x��" << endl;//���פT
    cout << "4. �ۭq�C��" << endl;//�Ȼs�ƹC��
}

void Game::chooseGameMode()
{
    int gameMode;
    cin >> gameMode;
    this->gameMode = gameMode;

    //�C���Ҧ�1�B2�B3�B4
    if (this->gameMode == 1 || this->gameMode == 2 || this->gameMode == 3)
        pTable = new Table(this->gameMode);

    //�Ȼs����
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

    //��ܨ�L���ܴN�O�w�]���Ҧ�.
    else
        pTable = new Table();

}

void Game::action()
{
    char move;

    char alphabat;
    int number;

    cout << "��J:(�ʧ@, �y�Ъ��r��, �y�Ъ��Ʀr)" << endl;//��J�ʧ@�B�r���B�Ʀr
    cout << "(�ʧ@ = [f]���аO or [e]�ʧ@��)" << endl;//f�O���аO�Ae�O�ʧ@��

    cin >> move >> alphabat >> number;

    int i = number - 1;
    int j = int(alphabat) - 97;

    if ((move == 'e' || move == 'f'))
        if (this->pTable->isValid(i, j))
        {
            if (!this->pTable->pArray[i][j].getIsRevealed())
            {
                if (move == 'e') //�ʧ@��
                {
                    if (!this->pTable->pArray[i][j].isMine())
                    {
                        this->pTable->chainReveal(i, j);
                    }
                    else //�o�O�a�p.
                    {
                        if (numberOfMoves == 0) // �p�G�Ĥ@�U���a�p�A�o���a�p�|����O�B�C
                        {
                        }
                        else
                        {
                            this->gameOver();
                            this->pTable->revealAllMines();
                        }
                    }
                }
                else if (move == 'f') //�p�G�ʧ@"f"�O��X��
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