
#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b)     for(int i=a;i<b;i++)           

#define vii              vector<vector<int> >
#define ce               cout<<endl;
 int r1,c1,size,pxl;
int **arr;
// vector<vector<int> > allpaths;
// vector<int> path;
bool issafe(int **grid, int i, int j)
{   
        if(i<0 || j<0 || i>=r1 || j>=c1 || arr[grid[i][j]-1][9]==1)
                   {
                       return false;
                   }
                       
         return true;
}

bool solvegridrec(int **grid,int sr1,int sc1, int dr1,int dc1,vector<int> &path, int distance,int& mindist,vii & paths)
{  
    //  cout<<" sr1 "<<sr1<<" sc1 : "<<sc1<<" dr1 "<<dr1<<" dc1 "<< dc1<<" :: "<<" distance = "<<distance<<" mindist :: "<<mindist<<endl;
    
    if(!issafe(grid,sr1,sc1)) return false;
    if(mindist<distance) return false;
    if(grid[sr1][sc1]==grid[dr1][dc1])
    {   if(mindist>distance)
            {
                mindist=distance;
                path.push_back(grid[sr1][sc1]);
                paths.push_back(path);
                path.pop_back();
                return true;
            }
    }
    if(issafe(grid,sr1,sc1)==true)
    {    path.push_back(grid[sr1][sc1]);
         arr[grid[sr1][sc1]-1][9]=1;
         if(arr[grid[sr1][sc1]-1][1]==1 && solvegridrec(grid,sr1-1,sc1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                    NULL;
        if(arr[grid[sr1][sc1]-1][2]==1 && solvegridrec(grid,sr1-1,sc1+1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                    NULL;
       
        if(arr[grid[sr1][sc1]-1][3]==1 && solvegridrec(grid,sr1,sc1+1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
       
       
        if(arr[grid[sr1][sc1]-1][4]==1 && solvegridrec(grid,sr1+1,sc1+1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
        
        if(arr[grid[sr1][sc1]-1][5]==1 && solvegridrec(grid,sr1+1,sc1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
        
        if(arr[grid[sr1][sc1]-1][6]==1 && solvegridrec(grid,sr1+1,sc1-1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
        
        if(arr[grid[sr1][sc1]-1][7]==1 && solvegridrec(grid,sr1,sc1-1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
        
        if(arr[grid[sr1][sc1]-1][8]==1 && solvegridrec(grid,sr1-1,sc1-1,dr1,dc1,path,distance+1,mindist,paths)==true)
                // return true;
                NULL;
        
         arr[grid[sr1][sc1]-1][9]=0;
         path.pop_back();
    }
   
    return false;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin>>r1>>c1>>pxl;
    size=r1*c1;
     
    arr= new int *[size];
    for(int i=0;i<size;i++)
         {  arr[i]=new int[10];
             for(int j=0;j<9;j++)
             {
                cin>>arr[i][j];
            }
         }
    for(int i=0;i<size;i++)
    {
        arr[i][9]=0;
    }

    int num=1;
    int **grid;
    grid= new int *[r1];
    int sr1,sc1;
    for(int i=0;i<r1;i++)
         {  grid[i]=new int[c1];
             for(int j=0;j<c1;j++)
             {  if(num==pxl)
                {
                    sr1=i;
                    sc1=j;
                }   
                grid[i][j]=num;
                num++;
             }
         }

int dst[4][2]={{0,0},{0,c1-1},{r1-1,0},{r1-1,c1-1}};
// fo(k,0,4)
// {
//     fo(l,0,2) cout<<dst[k][l]<<" ";
//     cout<<endl;
// }
int dr1,dc1;
// cout<<" sr1 "<<sr1<<" sc1 "<<sc1<<endl;
for(int i=0;i<4;i++)
{ vector<int> path;
//   cout<<" in for with i "<<i<<endl;
  vii paths;
  dr1=dst[i][0];
  dc1=dst[i][1];
  int mindist=INT_MAX;
  int distance=0;
  solvegridrec(grid,sr1,sc1,dr1,dc1,path,distance,mindist,paths);   //solvegrid(grid,sr1,cr1,dr1,dr2,vector<int> path);
//   cout<<" min dist is "<<mindist<<endl;
//   cout<<" size of paths is "<<paths.size()<<endl;
  fo(sd,0,paths.size())
  {  if(paths[sd].size()==mindist+1)
       {   fo(df,0,paths[sd].size())
          {
              cout<<paths[sd][df]<<" ";
          }
          break;}
        //   ce;
      
  }
  cout<<"\n";
}
return 0;
}