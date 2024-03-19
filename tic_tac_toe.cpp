#include <iostream>
#include <vector>
using namespace std;

//FUNCTION FOR DISPLAYING THE TIC-TAC-TOE BOARD
void drawBoard(const vector<vector<char>> &board) {
    for(const auto &row : board) {
        for(char cell : row) {
            cout<<"|"<<cell<<"|";
        }
        cout<<endl; 
    }
}

//FUNCTION FOR CHECKING IF A PLAYER HAS WON OR NOT
bool checkWin(const vector<vector<char>> &board,char player) {
    //CONDITION FOR CHECKING DIAGONALS
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player || 
        board[0][2]==player && board[1][1]==player && board[2][0]==player)
    {
    return true;
    }

    //CONDITION FOR CHECKING ROWS AND COLUMNS
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i]==player && board[1][i]== player && board[2][i]==player ||
            board[i][0]==player && board[i][1]==player && board[i][2]==player)
        {
        return true;
        }
    }

    //IF NO CONDITION IS MET, IT MEANS NO ONE HAS WON YET
    return false;
}

//FUNCTION FOR CHECKING IF THE BOARD IS FULL OR NOT(DRAW CONDITION)
bool checkDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ')
            return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    int row,col;
    bool gameOver = false;

    while(!gameOver) 
    {
        drawBoard(board);
        cout<<"Player "<<player<<" turn, select the row and column from 0-2"<<endl;
        cin>>row>>col;
        
        if(board[row][col]==' ')
        {
            board[row][col]=player;
            gameOver = checkWin(board,player);
            if(gameOver)
            {
                drawBoard(board);
                cout<<"Player "<<player<<" wins !!"<<endl;
            }
            else if(checkDraw(board))
            {
                drawBoard(board);
                cout<<"It's a draw, no one won !!"<<endl;
                gameOver = true;
            }
            player = (player == 'X') ? 'O':'X';
        }
        else
        {
            cout<<"This space is already been taken, please choose other space"<<endl;
        }
    }
    return 0;
}