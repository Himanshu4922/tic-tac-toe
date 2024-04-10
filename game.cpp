#include <iostream>
using namespace std;

void printboard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];

            if (j < 2)
            {
                cout<<' '<< '|';
            }
        }
        cout << endl;

        if (i < 2)
        {
            cout << "---------" << endl;
        }
    }
}

bool makemove(char board[3][3], char player, int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ')
    {
        return false;
    }
    board[row][col] = player;

    return true;
}

bool checkwinner(char board[3][3], char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkdraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentplayer = 'X';
    bool gameover = false;

    while (!gameover)
    {
        printboard(board);

        int row, col;
        cout << "player " << currentplayer << " enter your move(row and column): ";
        cin >> row >> col;

        if (makemove(board, currentplayer, row, col))
        {
            if (checkwinner(board, currentplayer))
            {
                cout << "player " << currentplayer << " wins!"<<endl;
                printboard(board);
                gameover = true;
            }
            else if (checkdraw(board))
            {
                cout << "game is draw";
                printboard(board);
                gameover = true;
            }
            else
            {
                currentplayer = (currentplayer == 'X') ? '0' : 'X';
            }
        }
        else
        {
            cout << "invalid move! try again " << endl;
        }
    }

    return 0;
}