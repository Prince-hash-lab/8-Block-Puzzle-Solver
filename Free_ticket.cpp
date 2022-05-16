// {
// 	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
// 	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
// 	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
// 	// same ids are connected.
// 	// Example:
// 	// "Print to console": {
// 	// 	"prefix": "log",
// 	// 	"body": [
// 	// 		"console.log('$1');",
// 	// 		"$2"
// 	// 	],
// 	// 	"description": "Log output to console"
// 	// }
// }

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
using namespace __gnu_cxx;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vpii            vector< pii >
#define mii             map<int,int>
#define pq              priority_queue
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define fo(i,a,b)     for(int i=a;i<b;i++)           
#define setbits(x)      _buildin_popcountll(x)
#define zrobits(x)      _buildin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x ; cin>>x;while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
// mt19937                 rng(chrono:: steady_clock::now().time_since_epoch().count());
#define ce 				cout<<"\n";

// void addedge(vpii adj[],int u, int v,int w)
// {
//     adj[u].push_back(mp(v,w));
//     adj[v].push_back(mp(u,w));
//     cout<<" edge added is "<<u<<" "<<v<<" "<<w<<endl;
// }

// void printgraph(vpii adj[],int V)
// {
//     int v,w;
//     cout<<" in print graph function "<<endl;
//     fo(u,0,V)
//     {
//         cout<<" Node "<<u<<" makes an edge with \n";
//         for(vpii ::iterator it=adj[u].begin();it!=adj[u].end();it++)
//         {
//             v=it->first;
//             w=it->second;
//             cout<<"\tNode"<<v<<" with edge weight ="<<w<< " \n ";
//         }
//         ce
//     }
// }


int32_t main()
{
	FIO;
	int v,e,s,d,w;
    cin>>v>>e;
    vector<vi > edges;
    fo(i,0,e)
    {   cin>>s>>d>>w;
        edges.push_back({s,d,w});
    } 
    
    // vpii ::iterator it;
    // fo(j,0,v)
    // {  it=adj[j].begin();
    //     cout<<" ";
    // }

    // fo(i,0,e)
    // {    cin>>s>>d>>w;
    //      adj[s][d]=w;
    //      adj[d][s]=w;
    // }

    // printgraph(adj,v);
    
	return 0;
}
/*
4 5
1 2 10
1 3 24
2 3 2
2 4 15
3 4 7
*/