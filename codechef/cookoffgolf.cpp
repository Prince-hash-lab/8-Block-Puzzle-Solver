#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long  N,x,k,t;
     cin>>t;
     while(t--)
     {
         cin>>N>>x>>k;
        int flag=0;
         for(long long i=0;i<N+2 && flag!=1;i=i+k)
         {
             if(i==x) {cout<<"yes\n"; flag=1;}
            
         }
         for(long long j=N+1;j>=0  && flag!=1;j=j-k)
         {
             if(j==x)
             {
                 cout<<"yes\n";
                 flag=1;
             }
         }
         if(flag!=1)
         cout<<"No\n";
     }
     return 0;

}