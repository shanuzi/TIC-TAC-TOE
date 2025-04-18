#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
int check_win(char board[3][3]){

for(int i = 0; i < 3; i++){    
    if(board[i][0] != ' ' &&
       board[i][0] == board[i][1] && 
       board[i][1] == board[i][2] ){
          return (board[i][0] == 'X')? 1: 2 ; 
       }
       
    if(board[0][i] != ' ' &&
       board[0][i] == board[1][i] &&
       board[1][i] == board[2][i]){
          return (board[0][i] == 'X')? 1: 2 ;  
       }
}   
     if(board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] ==  board[2][2]){
         return (board[0][0] == 'X')? 1: 2 ;      
        }
        
      if(board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] ==  board[2][0]){
         return (board[0][0] == 'X')? 1: 2 ;      
   
} 
   return 0;

}
void draw_board(char board[3][3]){
            printf("_________________\n" );
            printf("|  %c  | %c  | %c  |\n", board[0][0], board[0][1], board[0][2]);
            printf("|_____|____|____|\n");
            printf("|  %c  | %c  | %c  |\n", board[1][0], board[1][1], board[1][2]);
            printf("|_____|____|____|\n" );
            printf("|   %c |  %c |  %c |\n", board[2][0], board[2][1], board[2][2]);
            printf("|_____|____|____|\n" );
}

int game(char pick, int row, int col, char board[3][3]){

    if(board[row][col] == 'X' || board[row][col] == 'O'){
        printf("This spot is occupied! by %c\n", board[row][col]);
        return 4;
    }
    board[row][col] = pick;
    draw_board(board);
    int win = check_win(board);
    if(win == 1){ return 1;}else if(win == 2){return 2;}
    
    int ctr = 0;
    for(int k = 0; k < 3; k++){
        for(int j = 0; j < 3;j ++){
            if(board[k][j] != ' ' ){ctr ++;}
        }
    }
    
    if(ctr == 9){
        return 3;
    }else{
        ctr = 0;
    }
   return 0; 
}

int main() {
    char pick;
    int row = 0, col = 0, WON = 24;
    char board[3][3] = {
    {' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}
}; 
 
    while(WON != 0){
    printf("Enter choice X or O: ");
    scanf(" %c", &pick);
    
    printf("Enter row to place: ");
    scanf("%d", &row);
    
    printf("Enter col to place: ");
    scanf("%d", &col);
    
    int WON = game(pick, row, col, board);
    
     if(WON == 1){
        printf("X wins!");
        break;
    }else if (WON == 2){
        printf("O wins!");
        break;
    }else if(WON == 3){
        printf("DRAW!");
        break;
    }
    }

    return 0;
}
