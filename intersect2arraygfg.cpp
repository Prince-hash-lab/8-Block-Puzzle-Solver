// { Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution{
    public:
    //Function to return a list containing the intersection of two arrays.
    vector<int> printIntersection(int a[], int b[], int n, int m) 
    { 
        //Your code here
        vector<int> v;
        int i=0,j=0,res=INT_MAX;
        while(i<n and j<m)
        {
            if(a[i] == b[j])
            {
                if(res!=a[i])
                {
                    res=a[i];
                    // cout<<res<<" ";
                    v.push_back(res);
                }
                    i++; j++;
                    // cout<<"i is ye "<<i<<" j is ye "<<j<<endl;
            // cout<<"    i 2 is ye "<<i<<" j 2 is ye "<<j<<" a[i] "<<a[i]<<" b[j] "<<b[j] <<endl;

            }
            if(i<n and j<m and a[i]>b[j]) j++;
            if(i<n and j<m and a[i]<b[j]) i++;
            // if(i==n || j==n ) return v;
            // cout<<"    i 2 is ye "<<i<<" j 2 is ye "<<j<<" a[i] "<<a[i]<<" b[j] "<<b[j] <<endl;

                
        }
        return v;
    }
    

};

// { Driver Code Starts.
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        Solution ob;
        // Function calling 
        // cout<<" in here ......"<<endl;
        vector<int> v;
        v = ob.printIntersection(arr1, arr2, N, M); 
        // cout<<" after func call \n";
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        // cout<<" in here ..2...."<<endl;
        cout << endl;
    }
    
  return 0; 
} 
  // } Driver Code Ends