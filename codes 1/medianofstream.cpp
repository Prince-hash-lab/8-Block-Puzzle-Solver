// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

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
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      _buildin_popcountll(x)
#define zrobits(x)      _buildin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x ; cin>>x;while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
//mt19937                 rng(chrono:: steady_clock::now().time_since_epoch().count());




class Solution
{
    public:
    pqb s;
    pqs g;
    double ans;
    //Function to insert heap.
    void insertHeap(int x)
    {
        if(s.empty() && g.empty()) { s.push(x); ans=x;return ;}
        if(s.size() > g.size())
        {

            // cout<< x<<" ....."<<endl;
            if(s.top()>x)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else g.push(x);
            // cout<<" s.top is ..."<<s.top()<<" s.pop() is ..."<< g.top()<<endl
            ans=(s.top()+g.top())/2.0;
        }
        else 
        {     
            // cout<< x<<" ..else ..."<<endl;
            if(x<=s.top()) s.push(x);
            else 
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            // cout<<" s.top is ..."<<s.top()<<endl;
            ans=s.top();
            
        }
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        NULL;
    }
    
    //Function to return Median.
    double getMedian()
    {
        return ans;
    }
};


// { Driver Code Starts.

int main()
{   FIO;
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends

//
/*
1
4
5
15
1
3
*/