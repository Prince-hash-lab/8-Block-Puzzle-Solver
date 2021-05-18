// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
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
#define mii             map<int,int>
#define pq              priority_queue
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

struct triplet
{
  int val ,apos,vpos;
  triplet(int v,int ap,int vp)
  {
      val=v; apos=ap; vpos=vp;
  }
};

struct mycmp
{
    bool operator()  (triplet &t1, triplet &t2)
    {
        return t1.val > t2.val;
    }
};

class Solution
{
    public:
    
    //Function to merge k sorted arrays.
    vi mergeKArrays(vector<vi> arr, int K)
    {   vector<int> res;
        pq<triplet,vector<triplet>,mycmp> pq1;
        for(int i=0;i<K;i++)
        {
            triplet t(arr[i][0],i,0);
            pq1.push(t);
        }
        while(!pq1.empty())
        {
            triplet curr=pq1.top();
            pq1.pop();
            res.pb(curr.val);
            int ap=curr.apos,vp=curr.vpos;
            if(vp+1 < K)
            {
                triplet t(arr[ap][vp+1],ap,vp+1);
                pq1.push(t);
            }
            
        }
        return res;
        //code here
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends