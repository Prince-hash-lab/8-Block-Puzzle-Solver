#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int board[N][N];
void printboard()
{
    for(int i=0;i<n;i++)
        {for(int j=0;j<n;j++)
           cout<<board[i][j]<<" ";
        cout<<endl;
        }
}

bool issafe(int row, int col)
{    for(int i=0;i<n;i++)
        if(board[row][i]==1) return false;
    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j]==1) return false;
    for(int i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j]==1) return false;
}

bool nqueen(int col)
{
    if(col==n) return true;
    for(int i=0;i<n;i++)
    {
        if(issafe(i,col))
        {
            board[i][col]=1;
            if(nqueen(col+1)) return true;
            else board[i][col]=0;
            
        }
    }
    return false;
    
}

int main()
{   
    cin>>n;
    if(nqueen(0))  printboard();
    else cout<<" no solution exist "<<endl;
    return 0;
}