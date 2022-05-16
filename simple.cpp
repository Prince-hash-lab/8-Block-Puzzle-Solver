// #include <bits/stdc++.h>
// using namespace std;

// struct Node  
// { 
//   int key; 
//   struct Node *left; 
//   struct Node *right; 
//   Node(int k){
//       key=k;
//       left=right=NULL;
//   }
// };

// int maxWidth(Node *root){
   
//     if (root ==NULL) return 0;
//     int count=1,res=1;
// 	cout<<" ------"<<endl;
//     queue <Node* > q;
//     q.push(root);q.push(NULL);
//     while(!q.empty() && q.front()!=NULL)
//     {
// 	cout<<" --[][][][][-"<<endl;
//         count=0;
//         while(q.front()!=NULL)
//         {
// 	        cout<<" @#@#@#@#@#@#@#$#%$"<<endl;
// 			cout<<" count is "<<count<<endl;
//             Node* curr =q.front(); q.pop();
//             if(curr->left!=NULL) { q.push(curr->left);count++;}
//             if(curr->right!=NULL) { q.push(curr->right);count++;}
            
//         }
//         q.push(NULL);
//         q.pop();
//         res=max(count, res);
// 		cout<< " res is "<< res<<endl;
//     }
//     return res;
// }  

// int main() {
	
// 	Node *root=new Node(10);
// 	root->left=new Node(20);
// 	root->right=new Node(30);
// 	root->left->left=new Node(40);
// 	root->left->right=new Node(50);
// 	root->right->left=new Node(60);
	
// 	cout<<maxWidth(root);
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n1=20 ,n2=70,c;
struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

void printstack(stack <Node*> s)
{
     while(!s.empty())
{    cout<<"|_"<<s.top()->key<<"_|"<<endl;
    s.pop();
}
}
void func(Node* root )
{
    if(root==NULL ) return ;
    Node* curr=root;
    stack <Node* > s;
    while(curr!=NULL || !s.empty())
    {   printstack(s);
        while(curr!=NULL)
        {
            s.push(curr);
            cout<<curr->key<<" ";
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        curr=curr->right;
    }    
}

// int cn=0;
// void func(Node* root)
// {
//     if(root==NULL) return ;
//     func(root->left);
//     func(root->right);
//     cn++;
// }
// bool flag =false;
//  bool lca(Node* root )
//  { 
//      if(root==NULL) return false;
//     //  cout<<root->key<<" ";
//      bool l1=lca(root->right);
//      bool l2=lca(root->left);
//      if( (l1 || l2) && (root->key==n1 || root->key==n2) && !flag)
//        {  
//            c=root->key;
//            flag=true;
//          return true;
//        }
//     if(l1 && l2 && !flag)
//     {
//         // cout<<root->key<<" second if "<<endl;
//         c=root->key;
//         flag=true;
//         // exit(0);
//         return true;
//     }
//     if(l1 || l2)
//     {
//         return true;
//     }
//     if(root->key==n1 || root->key==n2)  return true ; 
    
//     return false;


//  }
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	root->right->right->right=new Node(80);
    root->right->right->left=new Node(70);
    
	
	func(root);
    // cout<<cn;
}