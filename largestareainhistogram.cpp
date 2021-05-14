#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int arr[],int n){
   int ps[n];
   int ns[n];
   stack<int> s;
   ps[0]=-1;
   s.push(0);
   for(int i=1;i<n;i++)
   {
       while(!s.empty() && arr[i]<=arr[s.top()])  s.pop();
       int a=(s.empty())?(-1):(s.top());
       ps[i]=a;
       s.push(i);
   }
    // for(int j=0;j<n;j++)  cout<<ps[j]<<" "; cout<<endl;

   while(!s.empty()) s.pop();
   ns[n-1]=n;
   s.push(n-1);
   for(int i=n-2;i>=0;i--)
   {
       while(!s.empty() && arr[i]<=arr[s.top()])  s.pop();
       int a=(s.empty())?(n):(s.top());
       ns[i]=a;
       s.push(i);
   }
//   for(int j=0;j<n;j++)  cout<<ns[j]<<" "; cout<<endl<<" curr is "; 

   int res=0;
   for(int i=0;i<n;i++)
   {   
       int  curr=arr[i];
    //    cout<<curr<<" "<<" ps{i] "<<ps[i]<<" ns[i] "<<ns[i]<<endl;
    //    if(ps[i]!=-1)
            curr+=((i-ps[i]-1)*arr[i]);
    //    else curr+=(i*arr[i]);
    //    if
       curr+=((ns[i]-i-1)*arr[i]);
    //    cout<<curr<<" ";
       res=max(res,curr);
   }
   return res;
}

// void func(int arr[], int n)
// int ps[n];
// //    int ns[n];
//    stack<int> s;
//    ps[0]=-1;
//    s.push(0);
//    for(int i=1;i<n;i++)
//    {
//        while(!s.empty() && arr[i]<=arr[s.top()])  s.pop();
//        int a=(s.empty())?(-1):(s.top());
//        ps[i]=a;
//        s.push(i);
//    }
//    for
// }
int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}
