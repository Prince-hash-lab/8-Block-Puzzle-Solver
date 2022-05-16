#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define setbits(x)      _buildin_popcountll(x)
#define zrobits(x)      _buildin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x ; cin>>x;while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
mt19937                 rng(chrono:: steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int> , rb_tree_tag,tree_order_statistics_node_update> pbds;

bool sign(int num)
{
    return num>0;
}

int32_t main()
{
    FIO;
    w(t)
    {
        int n;cin>>n;
        mk(arr,n,int);
        for(int i=0;i<n;i++)
          cin>>arr[i];
        int ans=0;
        for(int i=0;i<n;++i)
        {
            int j=i;
            int mx=arr[i];
            while(j<n && sign(arr[i])==sign(arr[j]))
                mx=max(arr[j],mx),j++;
            i=j-1;
            ans+=mx;

        }
        cout<<ans<<'\n';

        }
    
    return 0;
}