#include <stdio.h>

// Color code definations
#define COLOR_X     "\x1b[31m"
#define COLOR_O    "\x1b[34m"
#define COLOR_RESET   "\x1b[0m"
#define colorGen "\e[0;93m"

// User-defined function to generate the game board
void printBoard(char board[4][4]) 
{
    printf("\t\t-----------------\n");
    
    for (int i = 0; i < 4; i++) 
    {
        printf("\t\t| ");
        
        if (board[i][0] == 'X') 
        {
            printf(COLOR_X "X" COLOR_RESET);
        }
        else if (board[i][0] == 'O') 
        {
            printf(COLOR_O "O" COLOR_RESET);
        }
        else
        {
            printf("%c", board[i][0]);
        }
            
        printf(" | ");

        if (board[i][1] == 'X') 
        {
            printf(COLOR_X "X" COLOR_RESET);
        }
        else if (board[i][1] == 'O') 
        {
            printf(COLOR_O "O" COLOR_RESET);
        }
        else
        {
            printf("%c", board[i][1]);
        }

        printf(" | ");

        if (board[i][2] == 'X') 
        {
            printf(COLOR_X "X" COLOR_RESET);
        }
        else if (board[i][2] == 'O') 
        {
            printf(COLOR_O "O" COLOR_RESET);
        }
        else
        {
            printf("%c", board[i][2]);
        }

        printf(" | ");

        if (board[i][3] == 'X') 
        {
            printf(COLOR_X "X" COLOR_RESET);
        }
        else if (board[i][3] == 'O') 
        {
            printf(COLOR_O "O" COLOR_RESET);
        }
        else
        {
            printf("%c", board[i][3]);
        }

        printf(" | ");
        printf("\n");

        printf("\t\t-----------------\n");
    }
}



// User-defined function to initialize the game board
void initializeBoard(char board[4][4]) 
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = ' ';
        }
    }
}


// User-defined function to check for winning conditions
char checkForMatch(char board[4][4]) 
{
    // Checking for horizontal and vertical match
    for (int i = 0; i < 4; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == board[i][3] && board[i][0] != ' ')
        {
            return board[i][0];
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == board[3][i] && board[0][i] != ' ')
        {
            return board[0][i];
        }
}

    // Checking for diagonal match
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[0][0] != ' ')
    {
        return board[0][0];
    }
    if (board[0][3] == board[1][2] && board[1][2] == board[2][1] && board[2][1] == board[3][0] && board[0][3] != ' ')
    {
        return board[0][3];
    }

    return ' '; // No winner found
}

// User-defined function to check if the board is full
int boardCapacity(char board[4][4]) 
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] == ' ')
                return 0; // Board is not full

    return 1; // Board is full
}


int main() 
{
    // Use for Main Menu
    int option;

    char player1_name[25], player2_name[25];

    char board[4][4] = {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}};
    int row, col;
    char strikingPlayer = 'O';

    do{
        // Main Menu of the Game
        printf(COLOR_X"\nX "COLOR_RESET);
        printf(COLOR_O"O "COLOR_RESET);
        printf("Tic Tac Toe");
        printf(COLOR_X" X "COLOR_RESET);
        printf(COLOR_O"O\n\n"COLOR_RESET);
        printf("1)"); 
        printf(colorGen"Play Game\n"COLOR_RESET);
        printf("2)"); 
        printf(colorGen"Game Rules\n"COLOR_RESET);
        printf("3)");
         printf(colorGen"Exit Game\n\n"COLOR_RESET);
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                initializeBoard(board); // Initializing Board to start a new game
                
                // User input for player name
                printf("Enter name for first player: ");
                scanf("%s", player1_name);

                printf("Enter name for second player: ");
                scanf("%s", player2_name);

                do {
                
                    printBoard(board);

        // Ask the player to play
        printf(colorGen "\n '%s' make your move (enter row & column index w/ a space in between): " COLOR_RESET, (strikingPlayer == 'X') ? player2_name : player1_name);

        scanf("%d %d", &row, &col);

        printf("\n");

        // Check for valid move
        if (row < 0 || row >= 4 || col < 0 || col >= 4 || board[row][col] != ' ') 
        {
            printf("Please enter a valid move.\n");
            continue;
        }

        // Next move
        board[row][col] = strikingPlayer;

        // Check for a winner
        char winner = checkForMatch(board);

        if (winner != ' ') 
        {
            printBoard(board);
            printf("'%s' won!\n", (winner == 'X') ? player2_name : player1_name);

            break;
        }

        // Check for a tie
        if (boardCapacity(board)) 
        {
            printBoard(board);
            printf("No one wins!\n");
            break;
        }

        // Switch to the other player
        strikingPlayer = (strikingPlayer == 'O') ? 'X' : 'O';

    }while(1);
                break;

            case 2:
                printf(colorGen"\nRule Book\n\n");
                printf("1) "COLOR_RESET);
                printf("Tic Tac Toe is a two player game.\n\n");
                printf(colorGen"2) "COLOR_RESET); 
                printf("Players take turns putting their markers (O or X) on a 16 square grid.\n\n");
                printf(colorGen"3) "COLOR_RESET);
                printf("In order to place a marker, you must enter the row and column indexs.\n\n");
                printf(colorGen"Example: "COLOR_RESET);
                printf("Input for placing a maker on row 1 column 4 -> 0 3\n\n");
                printf(colorGen"4) "COLOR_RESET);
                printf("The first player to get four of their marks in a sequence (horizontally/ vertically/ diagonally) wins the game.\n\n");
                printf(colorGen"5) "COLOR_RESET);
                printf("If none of the players are able to achieve the sequence and the board gets full, the game is tied.\n");
                break;

            case 3:
                printf(COLOR_X"X "COLOR_RESET);
                printf(COLOR_O"O "COLOR_RESET);
                printf("Game Exited Succesfuly");
                printf(COLOR_X" X"COLOR_RESET);
                printf(COLOR_O" O"COLOR_RESET);
                break;

            default:
                printf("Please enter a valid option.\n");
        }

    }while(option != 3);

    return 0;
}
