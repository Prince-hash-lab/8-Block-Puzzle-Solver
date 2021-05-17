#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long  t;
    cin>>t;
    while(t--)
    {
        long long n;
        long long count=0;
        cin>>n;
        
        for(long long i=1;i<=n;i++)
        {   long long temp=i;
            int flag=0;
            long long temp2=temp%10;
            while(temp!=0)
            {   
                if(temp%10 != temp2) {flag=1;break;}
                temp=temp/10;
            }
            if(flag==0)
            count++;

        }
        cout<<count<<endl;
        
    }
    return 0;
}