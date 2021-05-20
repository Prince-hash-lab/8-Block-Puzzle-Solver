
#include<bits/stdc++.h>
#include<stdint.h>
// #define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i<size ; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
// using namespace __gnu_pbds;
#define ff              first
#define ss              second
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vvi              vector<vi>
#define vpii            vector<pii>
#define mii             map<int,int>
#define pq              priority_queue
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define fo(i,a,b)       for(int i=a;i<b;i++)           
#define setbits(x)      _buildin_popcountll(x)
#define zrobits(x)      _buildin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x ; cin>>x;while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
// mt19937              rng(chrono:: steady_clock::now().time_since_epoch().count());
#define ce 				cout<<"\n";
int n,m;
const int N=1e5 + 3;
vvi g[N];
vi dist(N),parent(N);
vector<bool> vis(N);
const int INF=1e9;
int cost=0;
void primsMST(int source)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=INF;
    }
    set<vi> s;
    dist[source]=0;
    s.insert({0,source});
    while(!s.empty())
    {
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
        cout<<u<<" "<<w;
        cost+=w;
        for(auto it: g[x[1]])
        {
            if(vis[it[0]]) continue;
            if(dist[it[0]]>it[1])
            {
                s.erase({dist[it[0]],it[0]});
                dist[it[0]]=it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
        }
    }
}

int32_t main()
{
    cin>>n>>m;
    fo(i,0,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    primsMST(0);
    cout<<cost;
	return 0;
}