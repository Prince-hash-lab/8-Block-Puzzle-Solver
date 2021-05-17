#include<bits/stdc++.h>
#define ll long long int 
#define ull unsigned long long 
#define MODULO 1000000007
#define prince ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase int
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     long long n,m,t;
     cin>>t;
     while(t-- && t<=1000)
     {
        cin>>n>>m;
        int flag=0;
        for(long long i=1;i<=n && n<=1000000 && m<=(500000);i++)
        {
            for(long long j=i+1;j<=n ; j++)
            {
                if((((m% i) % j)==((m%j) %i)) && ((i+j)<=1000000)) flag++;
            }
        }
        cout<<flag<<"\n";
     }
     return 0;

}