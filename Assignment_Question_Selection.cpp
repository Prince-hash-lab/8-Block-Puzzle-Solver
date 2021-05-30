
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
//using namepace __gnu_cxx;
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

class obj
{   public:
    int qsno;
    int marks;
    int sbpts;
};

bool mycmp(const obj &a,const obj &b)
{
    if(a.sbpts != b.sbpts) return a.sbpts>b.sbpts;
    else
    {
        return (a.marks/a.sbpts)<(b.marks/b.sbpts);
    }
}

int32_t main()
{
	FIO;
	int minmarks,S,N;
    cin>>minmarks>>S>>N;
    vi smks;            // studnet marks
    fo(i,0,S)
    { int a;
    cin>>a;
    smks.pb(a);
    }
	obj quen[N];            // questions with marks
    fo(i,0,N)
    {
        obj o1;
        o1.qsno=i+1;
        cin>>o1.marks>>o1.sbpts;
        quen[i]=o1;
    }
    sort(quen,quen+N,mycmp);
    // fo(i,0,N)
    // {
    //     cout<<quen[i].qsno<<" ";
    //     cout<<quen[i].marks<<" ";
    //     cout<<quen[i].sbpts<<" ";
    //     cout<<endl;
    // }
    fo(i,0,S)
    {
        int subno=0;
        vi subarrno;
        while(smks[i]<minmarks)
        {
            subarrno.pb(quen[subno].qsno);
            smks[i]+=quen[subno++].marks;
        }
        sort(subarrno.begin(),subarrno.end());
        cout<<subarrno.size()<<" ";
        printArray(subarrno,subarrno.size());   
        cout<<endl;
    }
	return 0;
}
/* 75 3 5
15 50 35 
6 3
11 1
11 2
11 2
27 1
*/