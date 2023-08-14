#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';


void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);







int main(void){
    char winner = ' ';



    resetBoard();



    while (winner == ' ' && checkFreeSpaces() > 0) {
        printBoard();
        playerMove();
        winner = checkWinner();
        if (winner != ' ') {
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0){
            break;
        }

    }
    printBoard();
    printWinner(winner);






    return 0;
}

void resetBoard(){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}
int checkFreeSpaces(){
    int i, j, freeSpaces = 9;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(board[i][j] != ' '){
                freeSpaces--;
            }
        }
    }
    return freeSpaces;

}
void playerMove(){
    int x;
    int y;
    printf("Enter coordinates for your move: ");
    scanf("%d %d", &x, &y);
    x--;
    y--;
    if(board[x][y] != ' '){
        printf("Invalid move, try again.\n");
        playerMove();
    }
    else{
        board[x][y] = PLAYER;
    }

}
void computerMove(){
    int x;
    int y;
    srand(time(0));
    x = rand() % 3;
    y = rand() % 3;
    if(board[x][y] != ' '){
        computerMove();
    }
    else{
        board[x][y] = COMPUTER;
    }

}
char checkWinner(){
    int i;
    for(i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            return board[i][0];
        }
        else if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            return board[0][i];
        }
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        return board[0][0];
    }
    else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        return board[0][2];
    }
    else{
        return ' ';
    }
}
void printWinner(char winner){
    if(winner == PLAYER){
        printf("You win!\n");
    }
    else if(winner == COMPUTER){
        printf("You lose!\n");
    }
    else{
        printf("It's a tie!\n");
    }

}
