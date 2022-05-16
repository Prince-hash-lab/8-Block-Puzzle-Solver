// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

 // } Driver Code Ends



class Solution 
{
    public:

    // int count=0;
    // int ngrid[N][N];
    bool issafe(int grid[][N],int i,int j,int n)
    {   
        // cout<<endl<<" in safe func with i and j as "<<i<<" "<<j<<endl<<" grid  as"<<endl;
        // printGrid(grid);
        // cout<<endl<<"{}{}{}{}{}}{}{}{}"<<endl;
      
        for(int k=0;k<N;k++)
        if(grid[k][j]==n || grid[i][k]==n) return false;
        int s=sqrt(N);
        int rs=i-i%s;
        int cs=j-j%s;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(grid[i+rs][j+cs]==n) return false;
            }
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[][N])  
    { 
        // printGrid(grid);
        // cout<<".....in solvesudoku function ......"<<endl;
        int i,j; 
        int flag=0;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                if(grid[i][j]==0)
                {   flag=1;
                    break;
                    
                }
                
            }
            if(flag==1) break;
        }
        
        if(i==N && j==N) return true;
        for(int n=1;n<=N;n++)
        {
            if(issafe(grid,i,j,n))
            {
                grid[i][j]=n;
                if(SolveSudoku(grid)) return true;
                grid[i][j]=0;
            }
        }
        return false;
        // Your code here
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        // Your code here 
    }
};

// { Driver Code Starts.

int main() {
    FIO;
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        cout<<endl;
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
/*
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0

3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0

*/