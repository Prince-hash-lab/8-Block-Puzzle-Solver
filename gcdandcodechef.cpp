#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
LL gcd(LL a, LL b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main ()
{
    LL t;
    cin>>t;
    while(t--)
    {
         LL k;
         cin >>k;
         LL a =(2*k)+1;
         LL sum=0;
         for(LL i=1;i<a;i++)
         {    
             sum+=gcd(k+(i*i),k+((i+1)*(i+1)));
         }
         cout<<sum%1000000007<<endl;
    }

return 0;
}
//doubts 
// 80% not working actual coonstraints 
//