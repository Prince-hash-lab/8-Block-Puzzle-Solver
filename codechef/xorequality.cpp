#include<bits/stdc++.h>
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     long long  N,t;
     cin>>t;
     while(t--)
     {
        cin>>N;
        int flag=0;
        for(int i=0;i<pow(2,N);i++)
        {//  cout<<"i is "<<i<<" flag is "<<flag<<endl;
             int a1=(i^(i+1));
             int a2=((i+1)^(i+3));
             if(a1==a2) flag++;
        }
        cout<<flag<<"\n";
     }
     return 0;

}