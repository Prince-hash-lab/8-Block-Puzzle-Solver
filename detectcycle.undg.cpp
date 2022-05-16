// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    bool  dfs(bool visited[],int s, vector<int> adj[], int prev)
    {
        visited[s]=true;
        // rec[s]=true;
        for(int u : adj[s])
        {
            if (visited[u]==false && dfs(visited,u,adj,s)) return true;
            else if(visited[u]==true && u!=prev) return true;
            
        }
        return false;
        
    }
    //Function to detect cycle in an undirected graph.
	bool isCycle(int V, vector<int>adj[])
	{   bool visited[V];
// 	fill(visited,visited+V,false);
for(int i=0;i<V;i++)
{
visited[i]=false;
}
// 	 bool rec[V];
// 	fill(rec,rec+V,false);
	for(int i=0;i<V;i++)
	{
	    if(visited[i]==false && dfs(visited,i,adj,-1)) return true;
	    visited[i]=true;
	    
	}
	return false;
	    // Code here
	}
};

// { Driver Code Starts.
int main(){
       ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends