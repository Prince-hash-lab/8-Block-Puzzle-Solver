#include<bits/stdc++.h>
#define MODULO 1000000007
#define ull unsigned long long 
#define ll long long int 
#define prince ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define whl while(t--) {
#define we }
#define testcase int t; cin>>t;

using namespace std;
int main()
{
     prince
     ull n;
     testcase
     
     whl  // ll flag;
        cin>>n;
        if(n==1) cout<<"1\n";
        else{
              ull ans=1;
             ull a=2;
             n--;
             while(n>0)
             {
                  if(n&1) ans=ans* a%MODULO;
                  a=a*a%MODULO;
                  n>>=1;
             }
             cout<<ans<<"\n";
        }



     //    for(int i=0;i<pow(2,N);i++)
     //    {
     //         int a1=(i^(i+1));
     //         int a2=((i+1)^(i+3));
     //         if(a1==a2) flag++;
     //    }
     //    cout<<flag<<"\n";
     we
     return 0;

}