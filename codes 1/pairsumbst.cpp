
#include <bits/stdc++.h>
#include<set>
using namespace std;


struct Node {
    int data;
    struct Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


bool findPair(Node* root, int sum);

// Driver code
int main() {

    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n, x;
        cin >> n;
        int val;
        for (int i = 0; i < n; i++) {
            cin >> val;
            root = insert(root, val);
        }
        cin >> x;
        if (findPair(root, x))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }

    return 0;
}// } Driver Code Ends



set <int> s1;

//Function to check if any pair exists in BST whose sum is equal to given value.
bool findPair(Node* root, int sum) 
{
    // if(root==NULL) return false;
    // if(s1.find(sum-(root->data))!=s1.end()) return true;
    // s1.insert(root->data);
    // if(findPair(root->left,sum) || findPair(root->right,sum))
    //         return true;
    // return false;
    
    if(root==NULL) return false;
    if(findPair(root->left,sum)) return true;
    // if()
    if(s1.find(sum-(root->data))!=s1.end()) return true;
    else s1.insert(root->data);
    return findPair(root->right,sum);
    // Your code here
}



