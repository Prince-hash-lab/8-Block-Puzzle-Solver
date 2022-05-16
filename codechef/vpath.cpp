#pragma GCC optimize("Ofast","unroll-loops")

#include <iostream>
using namespace std;

#define int long long 
#define double long double 
using pii =pair<int,int>;
template<typename T>
using Prior =std::priority_queue <T>;
template<typename T>
using prior =std::priority_queue<T,vector<T>, greater<T>>;
#define X first
#define Y second
#define eb emplace_back
#define ALL(x) begin(x),end(x)
#define RALL(x) rbegin(x),rend(x)
#define fastIO() ios_base::sync_with_stdio(0), cin.tie(0)
mt19937_64 rng(chrono :: steady_clock::now().time_since_epoch().count());
inline int getrand(int L,int R)
{
    if(L<R)  swap(L,R);
    return (int)(rng() % (uint64_t)(R-L+1)+L);
    
} 
template<typename T1, typename T2>
ostream& operator << (ostream &os, pair<T1,T2> p)
{
    os<<"("<<p.first<<","<<p.second<<")";
    return os;
} 
template<typename T>
ostream& operator << (ostream &os , vector <T> vec)
{
    for(int i =0;i<vec.size();++i)
    {
        if(i) os<<" ";
        os<<vec[i];
    }
    return os;

}

const int maxn=3E5 +5;
const int mod=1E9 +7;
vector <int> adj[maxn], subval,val;
vector <pii> ch;


void dfs(int now , int lst=-1)
{
    for(auto x:adj[now])
    {
        if(x==lst)  continue;
        dfs(x,now);

    }
    ch.clear();
    for(auto x: adj[now])
    {
        if(auto x: adj[now])
                if(x!=lst) ch.eb(subval[x],x)
    }
    sort(RALL(ch));
    int tok=1;
    for(auto [_val,id] :ch) val[id]=tok++;
    for(auto x : adj[now])
            if(x!=lst) subval[now]+=val[x] * subval[x];

}
//}  missing here
void solve()
{
    int N,X;cin>>N>>X;
    subval.assign(N,1),val.assign(N,0);
    for(int i=0;i<N;++i) vector<int>().swap(adj[i]);

    for(int i=0;i<N;++i)
    {
        int u,v; cin>>u>>v,--u,--v;
        adj[u].eb(v).adj[v].eb(u);   }
    dfs(0);
    cout<<subval[0]%mod* X % mod <<"\n";
}


int32_t main() {
    fastIO();
    int t=1;cin>>t;
    for(int _ =1;_<=t ; ++_)
            solve();
	// your code goes here
	return 0;
}


/* 

You are given a tree with N nodes numbered from 1 to N. A set S of nodes is called valid if there exist two vertices u and v (possibly, u=v) such that every node in S lies on the simple path from u to v.

Count the number of valid sets modulo 109+7. Two sets are different if one node is included in one set and not in the other. If there are multiple pairs (u,v) making a set valid, that set is still only counted once.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains N lines of input.
The first line contains a single integer N, the number of tree nodes.
Each of the next N−1 lines contains two space-separated integers u and v representing an edge between nodes u and v.
Output
For each test case, output in a single line the number of valid sets modulo 109+7.

Constraints
1≤T≤50
1≤N≤105
1≤u,v≤N
Sum N over all testcases is at most 5⋅105.
The given input is a valid tree.
Subtasks
Subtask #1 (20 points):

1≤T≤10
1≤N≤3⋅103
Subtask #2 (80 points): Original Constraints

Sample Input
2
4
1 2
3 1
2 4
4
1 2
2 3
2 4
Sample Output
15
13
Explanation
Test Case 1: Every non-empty set is valid.

Test Case 2: The valid sets are  {1} , {2}, {3}, {4}, {1,2}, {1,3}, {1,4}, {2,3}, {2,4}, {3,4}, {1,2,3}, {1,2,4}, {2,3,4}.


*/