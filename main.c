#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define x 6
#define y 7

char playerNames[2][20];

void printBoard(int board[x][y]);
int getInput(char *label);
int checkWin(int board[x][y], int player);
int checkDraw(int board[x][y]);
int checkColumn(int board[x][y], int player);
int checkRow(int board[x][y], int player);
int checkDiagonal(int board[x][y], int player);
void printCredits();
void printRules();
void getPlayerNames();

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
        {
            printRules();
            return 0;
        }

        if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "--credits") == 0)
        {
            printCredits();
            return 0;
        }
    }

    getPlayerNames();

    int board[x][y];
    int player = 1;
    int winner = 0;
    int full = 0;
    int input;
    int i;
    int j;

    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            board[i][j] = 0;
        }
    }

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

    while (winner == 0 && full == 0)
    {
        input = getInput("Enter a number: ");

        if (board[0][input - 1] != 0)
        {
            printf("Column is full, try again...");
        }
        else
        {
            for (i = x - 1; i >= 0; i--)
            {
                if (board[i][input - 1] == 0)
                {
                    board[i][input - 1] = player;
                    break;
                }
            }

            winner = checkWin(board, player);

            full = checkDraw(board);

            if (player == 1)
            {
                player = 2;
                printf("%s's turn (2) \n", playerNames[1]);
            }
            else
            {
                player = 1;
                printf("%s's turn (1) \n", playerNames[0]);
            }
        }

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

    if (winner == 1)
    {
        printf("%s wins! \n", playerNames[player - 1]);
    }
    else
    {
        printf("It's a tie!");
    }

    printCredits();

    return 0;
}

void printBoard(int board[x][y])
{
    int i;
    int j;

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
    char input[2];
    int inputInt;
    int valid = 0;

    while (valid == 0)
    {
        printf("%s", label);
        fgets(input, 2, stdin);

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
    int win = 0;

    if (checkColumn(board, player) == 1 || checkRow(board, player) == 1 || checkDiagonal(board, player) == 1)
    {
        win = 1;
    }

    return win;
}

int checkDraw(int board[x][y])
{
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

void printCredits()
{
    printf("\n\nCreated by: Abdoulaye Dia - Pascal Zhou - Cheikh - Clyde\n2022 - 2023\nPiscine C\n");
}

void printMenu()
{
    printf("Welcome to Connect 4!\n");
    printf("1. Play\n");
    printf("2. Credits\n");
    printf("3. Quit\n");
}

void printRules()
{
    printf("Puissance 4 est un jeu de société pour deux joueurs.\n \n");
    printf("Le but du jeu est d'aligner 4 pions de sa couleur avant son adversaire.\n \n");
    printf("Le jeu se joue sur une grille de 6 lignes et 7 colonnes, composée de 42 cases.\n \n");
    printf("Au début du jeu, les deux joueurs placent leurs pions dans la colonne de leur choix, de haut en bas.\n \n");
    printf("Si un joueur aligne 4 pions de sa couleur, il gagne la partie.\n \n");
    printf("Si la grille est remplie sans qu'aucun joueur n'ait aligné 4 pions, la partie est déclarée nulle.\n \n");
}

void getPlayerNames()
{
    // get the player names from config.txt, the format is PLAYERX=NAME
    FILE *config = fopen("config.txt", "r");
    if (config == NULL)
    {
        printf("Error: config.txt not found\n");
        return;
    }

    char line[50];
    int j = 0;
    while (fgets(line, sizeof(line), config))
    {
        char *token = strtok(line, "=");
        token = strtok(NULL, "=");
        strcpy(playerNames[j], token);
        playerNames[j][strlen(playerNames[j]) - 1] = '\0';
        j++;
    }
    fclose(config);
}