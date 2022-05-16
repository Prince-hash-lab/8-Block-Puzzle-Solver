//may challenge
#include<bits/stdc++.h>
#define MODULO 1000000007
#define ull unsigned long long 
#define ll long long int 
#define whl while(t--) {
#define we }
#define testcase int t; cin>>t;
#define prince ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int ticktoe(char b[3][3])
{
    int count_x=0;
    int count_O=0;
    int n=0;
    int wx=0;
    int wo=0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(b[i][j]=='O') count_O+=1;
            else if (b[i][j]=='X') count_x+=1;
            else n+=1;
        }
    }

    if((b[0][0]=='O' && b[0][1]=='O' && b[0][2]=='O')  ||
    (b[0][0]=='O' && b[1][0]=='O' && b[2][0]=='O')  ||
    (b[1][0]=='O' && b[1][1]=='O' && b[1][2]=='O')  ||
    (b[0][2]=='O' && b[1][2]=='O' && b[2][2]=='O')  ||
    (b[0][0]=='O' && b[1][1]=='O' && b[2][2]=='O') ||
    (b[2][0]=='O' && b[2][1]=='O' && b[2][2]=='O')  ||
    (b[0][1]=='O' && b[1][1]=='O' && b[2][1]=='O')  ||
    (b[0][2]=='O' && b[1][1]=='O' && b[2][0]=='O') ) wo=1;

    if((b[0][0]=='X' && b[0][1]=='X' && b[0][2]=='X')  ||
       (b[1][0]=='X' && b[1][1]=='X' && b[1][2]=='X')  ||
        (b[0][2]=='X' && b[1][2]=='X' && b[2][2]=='X')  ||
        (b[2][0]=='X' && b[2][1]=='X' && b[2][2]=='X')  ||
        (b[0][0]=='X' && b[1][1]=='X' && b[2][2]=='X')  ||
        (b[0][1]=='X' && b[1][1]=='X' && b[2][1]=='X')  ||
        (b[0][0]=='X' && b[1][0]=='X' && b[2][0]=='X')  ||
        (b[0][2]=='X' && b[1][1]=='X' && b[2][0]=='X') ) wx=1;

 if((wx==1 && wo==1) || (count_x - count_O < 0 ) || (count_x -count_O >1)) return 3;
  else if( n==9 && count_O==0 && count_x==0  ) return 2; 
  else if (wo==0 && wx==1 && count_O<count_x) return 1;
  else if (wo==0 && wo==1 && count_x==count_O) return 1;
  else if(wo==0 && n==0 && wx==0 ) return 1;
  else if (wo==0 && n>0 && wx==0 ) return 2;
  else 
  return 3;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
     prince
    //  ull n;
     testcase
     
     whl  // ll flag;
      char board[3][3];
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<3;j++)
          {
              cin>>board[i][j];
          }
      }
      cout<<ticktoe(board)<<"\n";
     we
     return 0;

}