#include <iostream>
using namespace std;

void init(int board[][3]); //Initializes the board with 0's
char printBlock(int block); //Prints each square of the board
void show(int board[][3]); //Show the board
void playMove(int board[][3], int); //Play one move
int checkContinue (int *board[3]); //Check if there is still white space
int checkWin(int *board[3]); //Check if anyone won
int game(int board[][3]); //Play an entire game
void scoreboard(int, int & , int &); //Show the scoreboard


int main(){
    int board [3][3];
    int cont = 0, player1 = 0, player2 = 0, result;

    do {
        init(board);
        result = game(board);
        show(board);
        scoreboard(result, player1, player2);

        cout<<"\n Outra partida?"<<endl;
        cout<<"0. Sair"<<endl;
        cout<<"1. Jogar de novo"<<endl;
    }while(cont);
    return 0;
}

void init(int board[][3]){
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = 0;
}

char printBlock(int block){
    if (block==0)
        return ' ';
    else if (block == 1)
        return 'X';
    else 
        return '0';
}

void show (int board[][3]) {
    cout<<endl;
    for (int row = 0; row < 3; row++){
        cout<<" "<< printBlock(board[row][0]) <<" |";
        cout<<" "<< printBlock(board[row][1]) <<" |";
        cout<<" "<< printBlock(board[row][2]) <<endl;

        if(row!=2){
            cout<<"__ __ __\n"<<endl;
        }
    }
}

void playMove (int board[][3], int player) {
    int row, col, check;
    do{
        cout<<"Linha: ";
        cin >>row;
        cout<<"Coluna: ";
        cin >> col;
        row--; col--;

        check = board[row][col] || row<0 || row>2 || col<0 || col>2;
        if (check)
            cout<<"Essa casa não está vazia ou fora do intervalo 3x3"<<endl;
    }while(check);

    if (player == 0)
        board[row][col] = 1;
    else 
        board[row][col] = -1;
}