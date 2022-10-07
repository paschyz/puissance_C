#include <stdio.h>
#include <stdlib.h>

#define x 6
#define y 7

// declare global functions
void printBoard(int board[x][y]);
int getInput(char *label);
int checkWin(int board[x][y], int player);
int checkDraw(int board[x][y]);
int checkColumn(int board[x][y], int player);
int checkRow(int board[x][y], int player);
int checkDiagonal(int board[x][y], int player);

int main()
{

    // connect 4 game while the input is not 0, keep playing the game two players (1 and 2) and the board is 6x7 (x and y) and the game is over when there is a winner or the board is full
    int board[x][y];
    int player = 1;
    int winner = 0;
    int full = 0;
    int input;
    int i;
    int j;

    // initialize the board
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            board[i][j] = 0;
        }
    }

    // print the board

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (j == y - 1)
            {
                printf("| %d |", board[i][j]);
            }
            else
            {
                printf("| %d ", board[i][j]);
            }
        }
        printf("\n");
    }

    // game loop
    while (winner == 0 && full == 0)
    {
        // get input from user and validate it (only 1 char) and digit
        input = getInput("Enter a number: ");

        // check if the column is full
        if (board[0][input - 1] != 0)
        {
            printf("Column is full, try again...");
        }
        else
        {
            // place the player's piece in the lowest available spot
            for (i = x - 1; i >= 0; i--)
            {
                if (board[i][input - 1] == 0)
                {
                    board[i][input - 1] = player;
                    break;
                }
            }

            // check if there is a winner
            winner = checkWin(board, player);

            full = checkDraw(board);

            // switch player
            if (player == 1)
            {
                player = 2;
            }
            else
            {
                player = 1;
            }
        }

        // print the board
        printf("\n");
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (j == y - 1)
                {
                    printf("| %d |", board[i][j]);
                }
                else
                {
                    printf("| %d ", board[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    // print the winner
    if (winner == 1)
    {
        printf("Player %d wins!", player);
    }
    else
    {
        printf("It's a tie!");
    }

    return 0;
}

// define global functions
void printBoard(int board[x][y])
{
    int i;
    int j;

    // print the board
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int getInput(char *label)
{
    // get input from user and validate it (only 1 char) and digit
    char input[2];
    int inputInt;
    int valid = 0;

    while (valid == 0)
    {
        printf("%s", label);
        fgets(input, 2, stdin);
        // remove the newline character

        inputInt = atoi(input);
        if (inputInt > 0 && inputInt < 8 && inputInt > 0 && inputInt < 8)
        {
            valid = 1;
        }
        else
        {
            printf("Invalid input, try again...");
        }
        fflush(stdin);
    }

    return inputInt;
}

int checkWin(int board[x][y], int player)
{
    // check if there is a winner
    int win = 0;

    // check if there is a winner
    if (checkColumn(board, player) == 1 || checkRow(board, player) == 1 || checkDiagonal(board, player) == 1)
    {
        win = 1;
    }

    return win;
}

int checkDraw(int board[x][y])
{
    // check if the board is full
    int full = 1;
    int i;
    int j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (board[i][j] == 0)
            {
                full = 0;
                break;
            }
        }
    }

    return full;
}

int checkColumn(int board[x][y], int player)
{
    // check if there is a winner in a column
    int win = 0;
    int i;
    int j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
            {
                win = 1;
                break;
            }
        }
    }

    return win;
}

int checkRow(int board[x][y], int player)
{
    // check if there is a winner in a row
    int win = 0;
    int i;
    int j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
            {
                win = 1;
                break;
            }
        }
    }

    return win;
}

int checkDiagonal(int board[x][y], int player)
{
    // check if there is a winner in a diagonal
    int win = 0;
    int i;
    int j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
            {
                win = 1;
                break;
            }
        }
    }

    return win;
}
