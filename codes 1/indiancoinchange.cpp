
#include<bits/stdc++.h>
#include<stdint.h>
#define N 105
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
#define vpii            vector<pii>
#define mii             map<int,int>
#define pq              priority_queue
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define flop(i,a,b)     for(int i=a;i<b;i++)           
#define setbits(x)      _buildin_popcountll(x)
#define zrobits(x)      _buildin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x ; cin>>x;while(x--)
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
// mt19937                 rng(chrono:: steady_clock::now().time_since_epoch().count());

int32_t main()
{
    // int arr[10]={1,2,5,10,20,50,100,200,500,2000};
    // sort(arr,arr+10, greater<int>() );
    // int n=54;
    // int count=0;
    // int i=9;
    // while(n!=0)
    // {   if(i==-1) break;
    //     if(arr[i]<=n)
    //     {
    //         count++;
    //         n-=arr[i];
    //         continue;
    //     }
    //     i--;
    // }
    int n; 
    cin>>n;
    vi a(n);
    flop(i,0,n)  cin>>a[i];
    int x;
    cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int ans=0;
    flop(i,0,n)
    {
        ans+=x/a[i];
        x-=(x/a[i])*a[i];
    }
    cout<<ans<<" ";

    return 0;
}
//C:\Users\my pc\Documents\c1codeforces