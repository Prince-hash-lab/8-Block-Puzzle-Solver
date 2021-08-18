
#include<bits/stdc++.h>
#include<stdint.h>
// #define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i<size ; i++)
	cout << arr[i] << " ";
}

int factorial(int n)
{
    // single line to find factorial
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}

 // } Driver Code Ends
//User function Template for C++
// using namespace __gnu_pbds;
//using namepace __gnu_cxx;
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vpii            vector<pii>
#define mii             map<int,int>
#define pq              priority_queue
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define fo(a,b)         for(int i=a;i<b;i++)           
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
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
 void delEdge(vector<int> adj[], int u, int v)
{
    // Traversing through the first vector list
    // and removing the second element from it
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            adj[u].erase(adj[u].begin() + i);
            break;
        }
    }
 
    // Traversing through the second vector list
    // and removing the first element from it
    for (int i = 0; i < adj[v].size(); i++) {
        if (adj[v][i] == u) {
            adj[v].erase(adj[v].begin() + i);
            break;
        }
    }
}
// A utility function to print the adjacency list
// representation of graph
bool checkvul(vector<int> adj[], int V)
{
    int fg=0;
    for (int v = 0; v < V; ++v)
    {
        fg=0;
        if(adj[v].size()==0) continue;
        for (int x=0; x<adj[v].size(); x++)
        {
            if(adj[v][x]<v) {fg=1; break;}
        }
        if(fg==0)
        {
            return true;
        }
        // printf("\n");
    }
    return false;
}
void delvul(vector<int> adj[], int V)
{
    int fg=0;
    for (int v = 0; v < V; ++v)
    {
        fg=0;
        if(adj[v].size()==0) continue;
        for (int x=0; x<adj[v].size(); x++)
        {
            if(adj[v][x]<v) {fg=1; break;}
        }
        if(fg==0)
        {
             for (int x=0; x<adj[v].size(); x++)
            {
                delEdge(adj, adj[v][x], v);
            } 
        }
        // printf("\n");
    }
}
void printGraph(vector<int> adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\n Adjacency list of vertex "<< v << "\n head ";
        for (int x=0; x<adj[v].size(); x++)
           cout << "-> " << adj[v][x];
        printf("\n");
    }
}
 
int num(vector<int> adj[], int V)
{
    int val=0;
    for (int v = 0; v < V; ++v)
    {
        
        if(adj[v].size()==0) continue;
        else  val++;
    }
    return val;
}
int32_t main()
{
	FIO;
	
        int v, e , s1, e1, q, qn;
        cin>>v>>e;
        vector<int> adj[v];
        fo(0,e)
        {
            cin>>s1>>e1;
            addEdge(adj,s1,e1);
        }
        cin>>q;
        while(q--)
        {
            cin>>qn;
            if(qn==1)
            {
                cin>>s1>>e1;
                addEdge(adj, s1, e1);
            }
            else if(qn==2)
            {
                cin>>s1>>e1;
                delEdge(adj, s1, e1);
            }
            else if(qn==3)
            {
                while(checkvul(adj, v))
                {
                    delvul(adj, v);
                }
                cout<<num(adj, v)<<endl;
            }
            printGraph(adj, v);
        }
    
	return 0;
}
