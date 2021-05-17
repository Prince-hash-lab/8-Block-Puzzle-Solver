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
        int k;cin>>k;
        mk(arr,n,int);
        for(int i=0;i<n;i++)
          cin>>arr[i];
        vi mxvls, mnvls;
        mii sum_cnt;
        for(int i=0;i<n/2;++i)
        {
            int mn=min(arr[i],arr[n-i-1]);
            int mx=max(arr[i],arr[n-i-1]);
            mxvls.pb(mx);
            mnvls.pb(mn);
            sum_cnt[mx+mn]++;

        }
        sort(mxvls.begin(),mxvls.end());
        sort(mnvls.begin(),mnvls.end());
        int ans=inf;
        for(int x=2;x<=2*k;++x)
        {
            int mx_less_than_x_plus_k=lower_bound(mxvls.begin(),mxvls.end(),x-k)-mxvls.begin();
            int mn_less_than_x=lower_bound(mnvls.begin(),mnvls.end(),x)-mnvls.begin();
            int  mn_greater_than_x_minus_1=n/2-mn_less_than_x;
            
            int cost_2=mn_greater_than_x_minus_1+mx_less_than_x_plus_k;
            int cost_0=sum_cnt[x];
            int cost_1=n/2-cost_0-cost_2;
            ans=min(ans,cost_2*2+cost_1*1);
        }

        cout<<ans<<'\n';
    }
    
    return 0;
}