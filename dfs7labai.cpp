#include <bits/stdc++.h>
using namespace std;
#define n 3

// struct node for each state ,  TO STORE THE LEVELS SO AS TO BACKTRACK AND PRINT AT THE END WHEN SOLUTION
//IS FOUND
struct node
{   public:
     node* father;
     int mat[n][n];
     int level;
};
// to check if empty block movement is feasible or not
//जाँच करें कि क्या खाली ब्लॉक चलना संभव है या नहीं
bool issafe(int i,int j)
{
    if(i>2 || j>2 || i<0 || j<0) return false;
    return true;
}

// compare at each level that current state is equal to goal state or not
//प्रत्येक स्तर पर तुलना करें कि वर्तमान स्थिति लक्ष्य स्थिति के बराबर है या नहीं
bool compmat(int mat1[n][n], int mat2[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
           if(mat1[i][j]!=mat2[i][j]) 
                    return false;
    }
    return true;
    
}
//print the matrix at each level while backtracking
//बैकग्राउंडिंग होने पर प्रत्येक स्तर पर मैट्रिक्स प्रिंट करें
void printMatrix(int mat[n][n])
{   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
       
    }
     cout<<"------------------"<<endl;
}


// to back track from final node to intial node and then 
//if initial node is reached printing  matrix of each node from initial node to final node 
void printpath(node* a)
{   
    if(a==NULL) return ;
    printpath(a->father);
    printMatrix(a->mat);
}

// to check if the final node is same as any of its parent node 
//if same that means it may stuck in a loop
bool check_same_as_parents(node* son,int childmat[n][n])
{
      if(son==NULL) return false;
      if(compmat(son->mat,childmat)) return true;
      return check_same_as_parents(son->father,childmat);
}
//  dfs algorithm

void dfs(int mat1[n][n],int i , int j,int previ,int prevj, int mat2[n][n],node* parent,int levl)
{   node* child=new node;
    child->father=parent;
    child->level=levl;
    memcpy(child->mat, mat1, sizeof child->mat); // copy content of mat1 to child->mat1
    if(check_same_as_parents(child->father,mat1)) //to check if it stucked in loop or not
    // if stuck in loop then break
    {   return;}

   
    if(compmat(mat1,mat2))          //at any instant if current state is equal to final state
    //print the path using backtracking
    { cout<<"printing path"<<endl;
        printpath(child);
        cout<<endl<<levl<<" no of states printed ";
        exit(0);
    }
    if(issafe(i+1,j) && previ!=i+1 ) //going down यह नीचे चला जाएगा
    {
        swap(mat1[i][j],mat1[i+1][j]);
        dfs(mat1,i+1,j,i,j,mat2,child,levl+1);
        swap(mat1[i][j],mat1[i+1][j]);

    }
    if(issafe(i-1,j) && previ!=i-1 )  //going up   यह ऊपर जाएगा
    {
        swap(mat1[i][j],mat1[i-1][j]);
        dfs(mat1,i-1,j,i,j,mat2,child,levl+1);
        swap(mat1[i][j],mat1[i-1][j]);

    }
    if(issafe(i,j-1) && prevj!=j-1)    //going left   यह बाईं ओर जाएगा
    {
        swap(mat1[i][j],mat1[i][j-1]);
        dfs(mat1,i,j-1,i,j,mat2,child,levl+1);
        swap(mat1[i][j],mat1[i][j-1]);
    }
    if(issafe(i,j+1) && prevj!=j+1)     //going right   यह दायें ओर जाएगा
    {
        swap(mat1[i][j],mat1[i][j+1]);
        dfs(mat1,i,j+1,i,j,mat2,child,levl+1);
        swap(mat1[i][j],mat1[i][j+1]);
    }
}
 
int main() {

    //intial state  प्रारम्भिक अवस्था
    int initial[n][n] =
    {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };
 
   //final state   अंतिम स्थिति
    int final[n][n] =
    {
        {2, 8, 1},
        {0, 4, 3},
        {7, 6, 5}
    };
    
    
	int x = 1, y = 1;    //position of 0 initially   पहले 0 की स्थिति
    node * parent =NULL;
    dfs(initial, x, y,-1,-1, final ,parent,0);  // calling dfs    कॉलिंग dfs
 
	return 0;     
}

// 46.67 seconds