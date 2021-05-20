
// #include<bits/stdc++.h>
// #include<stdint.h>
// // #define N 105
// using namespace std;
// void printArray(vector<int> arr, int size)
// {
// for (int i=0; i<size ; i++)
// 	cout << arr[i] << " ";
// }


//  // } Driver Code Ends
// //User function Template for C++
// // using namespace __gnu_pbds;
// #define ff              first
// #define ss              second
// // #define int             long long
// #define pb              push_back
// #define mp              make_pair
// #define pii             pair<int,int>
// #define vi              vector<int>
// #define vvi              vector<vi>
// #define vpii            vector<pii>
// #define mii             map<int,int>
// #define pq              priority_queue
// #define pqb             priority_queue<int>
// #define pqs             priority_queue<int,vi,greater<int>>
// #define fo(i,a,b)       for(int i=a;i<b;i++)           
// #define setbits(x)      _buildin_popcountll(x)
// #define zrobits(x)      _buildin_ctzll(x)
// #define mod             1000000007
// #define inf             1e18
// #define ps(x,y)         fixed<<setprecision(y)<<x
// #define mk(arr,n,type)  type *arr=new type[n];
// #define w(x)            int x ; cin>>x;while(x--)
// #define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
// // mt19937              rng(chrono:: steady_clock::now().time_since_epoch().count());
// #define ce 				cout<<"\n";
// int n,m;
// const int N=1e5 + 3;
// vvi g[N];
// vi dist(N),parent(N);
// vector<bool> vis(N);
// const int INF=1e9;
// int cost=0;
// void primsMST(int source)
// {
//     for(int i=0;i<n;i++)
//     {
//         dist[i]=INF;
//     }
//     set<vi> s;
//     dist[source]=0;
//     s.insert({0,source});
//     while(!s.empty())
//     {
//         auto x=*(s.begin());
//         s.erase(x);
//         vis[x[1]]=true;
//         int u=x[1];
//         int v=parent[x[1]];
//         int w=x[0];
//         cout<<u<<" "<<w;
//         cost+=w;
//         for(auto it: g[x[1]])
//         {
//             if(vis[it[0]]) continue;
//             if(dist[it[0]]>it[1])
//             {
//                 s.erase({dist[it[0]],it[0]});
//                 dist[it[0]]=it[1];
//                 s.insert({dist[it[0]],it[0]});
//                 parent[it[0]]=x[1];
//             }
//         }
//     }
//     cout<<cost;
// }

// int32_t main()
// {
//     cin>>n>>m;
//     fo(i,0,m)
//     {
//         int u,v,w;
//         cin>>u>>v>>w;
//         g[u].pb({v,w});
//         g[v].pb({u,w});
//     }
//     primsMST(0);
//     cout<<cost;
// 	return 0;
// }

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V],res=0;
        fill(key,key+V,INT_MAX);
        key[0]=0;
        bool mset[V]={false};
        for(int count=0;count<V;count++)
        {
            int u=-1;
            for(int i=0;i<V;i++)
            {
                if(!mset[i] && (u==-1 || key[i]<key[u])) u=i;
            
            }
            mset[u]=true;
            res=res+key[u];
            for(int v=0;v<V;v++)
            {
                if( (adj[u][v])!=0 && !mset[v])
                    key[v]=min(key[v],adj[u][v]);
            }
        }
        // code here
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector< vector<int> > adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends