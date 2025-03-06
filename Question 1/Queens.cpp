/* 
   The N-Queens problem is a fascinating puzzle where the goal is to place N-Queens on an N*N chessboard such that no two queens can be in the
   same row, same column or in a same diagonal.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> grid;

bool canPlaceQueen(int row, int col, int n){
    for(int i=row-1; i>=0; i--){  //check column
        if(grid[i][col] == 'Q') return false;
    }

    for(int i=row-1; i>=0; i--){
        if(grid[i][col] == 'Q') return false;
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){    // check left diagonal
        if(grid[i][j] == 'Q') return false;    // we are attacked
    }
    return true;    // No attack
}

void f(int row, int n){
    if(row==n){
        for(int i=0; i<n; i++){    // We got one possible answer
            for(int j=0; j<n; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int col=0; col<n; col++){
        if(canPlaceQueen(row, col, n)){
            grid[row][col] = 'Q';
            f(row+1, n);
            grid[row][col] = '.';
        }
    }
}

vector<vector<string>>nQueen(int n){
    grid.resize(n, vector<char>(n, '.' ));
    f(0, n);
}

int main(){
    nQueen(4);
    return 0;
}
