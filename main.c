#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Player Structure
typedef struct {
    int score;
    char name[30];
    char marker;
} player;


// Functions
void printScoreBoard (player playerOne, player playerTwo) {
    printf("+------SCORES-------+\n");
    printf("| %s           - %d |\n", playerOne.name, playerOne.score);
    printf("| %s           - %d |\n", playerTwo.name, playerTwo.score);
    printf("+-------------------+\n");
}



bool checkVictory(char playerTurn, char markerPositions[]){

    if (markerPositions[0] == playerTurn && markerPositions[3] == playerTurn && markerPositions[6] == playerTurn )
        return true;
    else if (markerPositions[1] == playerTurn && markerPositions[4] == playerTurn && markerPositions[7] == playerTurn )
        return true;
    else if (markerPositions[2] == playerTurn && markerPositions[5] == playerTurn && markerPositions[8] == playerTurn )
        return true;
    else if (markerPositions[0] == playerTurn && markerPositions[1] == playerTurn && markerPositions[2] == playerTurn )
        return true;
    else if (markerPositions[3] == playerTurn && markerPositions[4] == playerTurn && markerPositions[5] == playerTurn )
        return true;
    else if (markerPositions[6] == playerTurn && markerPositions[7] == playerTurn && markerPositions[8] == playerTurn )
        return true;
    else if (markerPositions[0] == playerTurn && markerPositions[4] == playerTurn && markerPositions[8] == playerTurn )
        return true;
    else if (markerPositions[2] == playerTurn && markerPositions[4] == playerTurn && markerPositions[6] == playerTurn )
        return true;
    else
        return false;


}

void printGameBoard (player playerOne, player playerTwo, char markerPositions[]){
    printf(" %c | %c | %c \n", markerPositions[0], markerPositions[1], markerPositions[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", markerPositions[3], markerPositions[4], markerPositions[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", markerPositions[6], markerPositions[7], markerPositions[8]);
}

int main()
{
    // Declarations
    player playerOne, playerTwo;
    playerOne.score = 0;
    playerTwo.score = 0;
    char playerTurnMarker;
    char playAgain;
    bool victorCondition = false;
    int numberofturns = 0;
    int playerCursor;
    char markerPositions[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

    // Getting Player names
    printf("Enter your name P1: ");
    scanf("%s", playerOne.name);

    printf("Enter your name P2: ");
    scanf("%s", playerTwo.name);

    // Getting Player Markers
    getPlayerMarkers:
        printf("%s Enter Your Marker Here (O/X): ", playerOne.name);
        scanf("\n%c", &playerOne.marker);
        playerOne.marker = toupper(playerOne.marker);

        switch (playerOne.marker)
        {
            case 'O':
                playerTwo.marker = 'X';
                break;
            case 'X':
                playerTwo.marker = 'O';
                break;
            default:
                printf("[ERROR] Invalid Input!\n");
                goto getPlayerMarkers;
                break;
        }

    // Printing Game Board and Score Board For First Turn
    printScoreBoard(playerOne, playerTwo);
    printGameBoard(playerOne, playerTwo, markerPositions);
    

    while (true)
    {

        // Player One's Turn
        
        playerTurnMarker = playerOne.marker;

        printf("%s's Turn! (%c): \n", playerOne.name, playerOne.marker);

        reinputposition1:
        printf("%s Enter The Position of Your Marker: ", playerOne.name);
        scanf("%d", &playerCursor);

        if (markerPositions[playerCursor-1] == 'O' || markerPositions[playerCursor-1] == 'X')
            goto reinputposition1;
        else
            markerPositions[playerCursor-1] = playerOne.marker;

        printScoreBoard (playerOne, playerTwo);
        printGameBoard(playerOne, playerTwo, markerPositions);


        if(checkVictory(playerTurnMarker, markerPositions)){
            playerOne.score++;
            printf("Do you want to play again?(Y/n): ");
            scanf("%c", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y')
                goto getPlayerMarkers;
            else
                break;
        }


        numberofturns++;   

        if (numberofturns == 9){
            printf("Match Draw");
            printf("Do you want to play again?(Y/n): ");
            scanf("%c", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y')
                goto getPlayerMarkers;
            else
                break;
        }
            

        


        // Player Two's Turn

        playerTurnMarker = playerTwo.marker;

        printf("%s's Turn! (%c): \n", playerTwo.name, playerTwo.marker);

        reinputposition2:
        printf("%s Enter The Position of Your Marker: ", playerTwo.name);
        scanf("%d", &playerCursor);

        if (markerPositions[playerCursor-1] == 'O' || markerPositions[playerCursor-1] == 'X')
            goto reinputposition2;
        else
            markerPositions[playerCursor-1] = playerTwo.marker;

        printScoreBoard (playerOne, playerTwo);
        printGameBoard(playerOne, playerTwo, markerPositions);

        
        if(checkVictory(playerTurnMarker, markerPositions)){
            playerTwo.score++;
            printf("Do you want to play again?(Y/n): ");
            scanf("%c", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y')
                goto getPlayerMarkers;
            else
                break;
            }
           
        

        numberofturns++;
        if (numberofturns == 9){
            printf("Match Draw\n");
            printf("Do you want to play again?(Y/n): ");
            scanf("%c", &playAgain);

            if (playAgain == 'Y' || playAgain == 'y')
                 goto getPlayerMarkers;
            else
                break;
            }
        
    
            
               
    }
    return 0;
}