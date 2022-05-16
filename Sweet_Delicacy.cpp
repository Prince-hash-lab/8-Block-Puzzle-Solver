#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    int val=0;
    while(n!=0)
    {  n=n-val;
        int i=1;
        // int ans=1;
       while(i<=n and n!=0 )
       
       {    if((2*i)>=n)
       {
           if((2*i)==n) val=2*i;
           else val=i;
           count++;
           break;
       }
           i=2*i;
           
       }
    //    cout<<count;
    //    return 0;
    }
    cout<<count;
    return 0;
}