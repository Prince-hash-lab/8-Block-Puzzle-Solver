// #include<bits/stdc++.h>
// using namespace std;
// void fun(int i)
// {
// 	if (i==5) {cout<<"exit "<<endl; return; }
// 	cout<<i<<" ";
// 	fun(i+1);
// }
// int main()
// {
// 	printf(" car");
// 	fun(1);

// 	cout<<" funciton enfed";
// 	return 0;
// }

// class Node {
// public:
// 		int data;
// 		Node(int d){
// 			data = d;
// 		}
// 		Node *ptr;
// };

// // Function to check if the linked list
// // is palindrome or not
// bool isPalin(Node* head){
// 		Node * curr=head;
//         queue <Node *> q;
//         q.push(curr);
//         while(!q.empty())
//         {
//             Node * cuur1=q.front();
//             q.pop();
//             if()

//         }
// }

// // Driver Code
// int main(){

// 	// Addition of linked list
// 	Node one = Node(1);
// 	Node two = Node(2);
// 	Node three = Node(3);
// 	Node four = Node(2);
// 	Node five = Node(1);

// 	// Initialize the next pointer
// 	// of every current pointer
// 	five.ptr = NULL;
// 	one.ptr = &two;
// 	two.ptr = &three;
// 	three.ptr = &four;
// 	four.ptr = &five;
// 	Node* temp = &one;

	
// 	// Call function to check palindrome or not
// 	int result = isPalin(&one);

// 	if(result == 1)
// 			cout<<"isPalindrome is true\n";
// 	else
// 		cout<<"isPalindrome is true\n";

// return 0;
// }

// // This code has been contributed by Striver
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
         if (n == 1)
                return 0;
 
    // Sort all elements
    sort(arr, arr+n);
 
    
 
    // Handle corner elements
    int small = arr[0] + k;
    int big = arr[n-1] - k;
    if (small > big)
       swap(small, big);
 
    // Traverse middle elements
    for (int i = 1; i < n-1; i++)
    {
        int subtract = arr[i] - k;
        int add = arr[i] + k;
 
        // If both subtraction and addition
        // do not change diff
        if (subtract >= small || add <= big)
            continue;
 
        // Either subtraction causes a smaller
        // number or addition causes a greater
        // number. Update small or big using
        // greedy approach (If big - subtract
        // causes smaller diff, update small
        // Else update big)
        if (big - subtract <= add - small)
            small = subtract;
        else
            big = add;
    }
 
   
        return big-small;
        // code here
   
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends