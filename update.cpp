#include <iostream>
using namespace std;

void printboard(char board[2][3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[0][i][j];

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

bool makemove(char board[2][3][3], char player, int row, int col)
{
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[1][row][col] != ' ')
    {
        return false;
    }
    board[0][row][col] = player;
    board[1][row][col] = player;

    return true;
}

bool checkwinner(char board[2][3][3], char player)
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[1][i][0] == player && board[1][i][1] == player && board[1][i][2] == player)
        {
            return true;
        }
        if (board[1][0][i] == player && board[1][1][i] == player && board[1][2][i] == player)
        {
            return true;
        }
    }

    if (board[1][0][0] == player && board[1][1][1] == player && board[1][2][2] == player)
    {
        return true;
    }

    if (board[1][0][2] == player && board[1][1][1] == player && board[1][2][0] == player)
    {
        return true;
    }

    return false;
}

bool checkdraw(char board[2][3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[1][i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    char board[2][3][3] = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'},},{{' ',' ',' '} , {' ',' ',' '},{' ',' ',' '}}};
    char currentplayer = 'X';
    bool gameover = false;

    while (!gameover)
    {
        printboard(board);

        int num,row,col;
        cout << "player " << currentplayer << " enter your move POSITION: ";
        cin >> num;
        row=(num-1)/3;
        col=(num-1)%3;

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