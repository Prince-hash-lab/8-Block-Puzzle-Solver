
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
int32_t main()
{
	FIO;
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        int a[n];
        int b[n];
        fo(0, n)
        {
            cin>>a[i];
        } 
        fo(0, n)
        {
            cin>>b[i];
        } 
        int ai=-1, val=n, cal,a1, a2;
        for(int i=0; i<n; i++)
        {
            cal=(a[0]+b[i])%n ;
            if(cal<val)
                {
                    ai=i;
                    // aj=j;
                    val=cal;
                }
            else if(cal==val)
            {
                int j=1;
                while(j<n)
                {
                    // cout<<" > ";
                    a1=(a[0]+b[(i+j)%n])%n;
                    a2=(a[0]+b[(ai+j)%n])%n;
                    if(a1>a2)
                    {
                        ai=i;
                        val=cal;
                        break;
                    }
                 j++;
                }
                // cout<<" ,  , ";
                // ce
            // }
            // for(int j=0; j<n;j++)
            // {
            //     
            //     
            }
        }
        // cout<<ai;
        // ce
        int i=0;
        for(int j=ai;i<n; j++)
        {

            // cout<<a[i]<<" "<<j%n<<endl;
            a[i]=(a[i]+b[j%n])%n;
            // cout<<a[i]<<" ";
            // ce
// 
            i++;
        }
         
         for(int k=0; k<n; k++)
           cout<<a[k]<<" ";
        ce

       
	}
	return 0;
}