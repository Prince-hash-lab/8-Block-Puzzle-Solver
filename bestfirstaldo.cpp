#include <bits/stdc++.h>
#include<iterator>
using namespace std;
#define n 3

// struct node for each state ,  TO STORE THE LEVELS SO AS TO BACKTRACK AND PRINT AT THE END WHEN SOLUTION
//IS FOUND   स्थिति को संचित करें  ताकि अंत में हम स्थिति को प्रिंट कर सकें
struct node
{   public:
     node* father;
     int mat[n][n];
     int i;
     int j;
     int previ;
     int prevj;
     int hval;
};
node* arr[362000];
int size;
int count1;
// to check if empty block movement is feasible or not
//जाँच करें कि क्या खाली ब्लॉक चलना संभव है या नहीं
bool issafe(int i,int j)
{
    if(i>2 || j>2 || i<0 || j<0) return false;
    return true;
}

// compare at each level that current state is equal to goal state or not
//प्रत्येक स्तर पर तुलना करें कि वर्तमान स्थिति लक्ष्य स्थिति के बराबर है या नहीं
bool compmat(int mat1[n][n], int mat2[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
           if(mat1[i][j]!=mat2[i][j]) 
                    return false;
    }
    return true;
    
}
//print the matrix at each level while backtracking
//बैकग्राउंडिंग होने पर प्रत्येक स्तर पर मैट्रिक्स प्रिंट करें
void printMatrix(int mat[n][n])
{   count1++;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
       
    }
     cout<<"------------------"<<endl;
}


// to back track from final node to intial node and then 
//if initial node is reached printing  matrix of each node from initial node to final node 
//अंतिम नोड से प्रारंभिक नोड तक बैकट्रैक।
//यदि प्रारंभिक नोड पहुँच गया है। हम प्रारंभिक नोड से अंतिम नोड तक प्रत्येक नोड का मैट्रिक्स प्रिंट करते हैं
void printpath(node* a)
{   
    if(a==NULL) return ;
    printpath(a->father);
    printMatrix(a->mat);
}

// to check if the final node is same as any of its parent node 
// यह जांचने के लिए कि क्या अंतिम नोड इसके मूल नोड के समान है

//if same that means it may stuck in a loop
// यदि ऐसा है तो इसका अर्थ है कि यह लूप में फंस सकता है
bool check_same_as_parents(node* son,int childmat[n][n])
{
      if(son==NULL) return false;
      if(compmat(son->mat,childmat)) return true;
      return check_same_as_parents(son->father,childmat);
}

void createnode(node* parent , int k , int l, int prevsi, int prevsj, int mat4[n][n])
{
    arr[size]=new node;
    arr[size]->father=parent;
    arr[size]->i=k;
    arr[size]->j=l;
    arr[size]->previ=prevsi;
    arr[size]->prevj=prevsj;
    for(int n1=0;n1<n;n1++)
    //=============================== // copy content of mat1 to child->mat1
    // एक दूसरे की सामग्री की प्रतिलिपि बनाएँ
      for(int n2=0;n2<n;n2++)
        arr[size]->mat[n1][n2]=mat4[n1][n2];
}

// this one will calculate the heruistic value for each node
//यह प्रत्येक नोड के लिए आनुवांशिक मूल्य की गणना करेगा
int calheruistic(node* Node, int actmat[n][n])
{   int hval=0;
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
              if(Node->mat[i][j]!=actmat[i][j])
                     hval++;
       
    }
    return hval;
}

// for sorting the vector which is taken as priority queue , according to heruistic value
//यह फ़ंक्शन वेक्टर को क्रमबद्ध करने के लिए है जिसे प्राथमिकता कतार के रूप में लिया जाता है, आनुवांशिक मूल्य के अनुसार
bool mycmp(node* one, node* two)
{
    return one->hval > two->hval;
}

// to check if current state is in, closed vector or not
// यह जांचने के लिए कि वर्तमान स्थिति, बंद वेक्टर में है या नहीं
bool inclosed(vector<node*> tclosed,node* ngbr)
{  
    vector<node*> :: iterator ptr;
   
   for (ptr = tclosed.begin(); ptr != tclosed.end(); ptr++)
       { 
           if(compmat((*ptr)->mat,ngbr->mat)) {return true;}         
       }
     
    return false;
}


void bestfirstsearch(int mat1[n][n],int k , int l, int mat2[n][n],node* parent)
{   vector<node*> que;        // taken as priority queue  प्राथमिकता कतार के रूप में लिया गया
    vector<node*> closed;       // this is vector of closed states यह बंद स्थिति का वेक्टर है
    size=0;
    createnode(parent,k,l,-1,-1,mat1);
    if(compmat(arr[size]->mat,mat2))          //at any instant if current state is equal to final state
         //किसी भी पल में यदि वर्तमान स्थिति अंतिम स्थिति के बराबर है
    //बैकट्रैकिंग का उपयोग करके पथ प्रिंट करें    //print the path using backtracking  
    { cout<<"printing path"<<endl;
    printpath(arr[size]);
    return ;
    }
    arr[size]->hval=calheruistic(arr[size],mat2);
    que.push_back(arr[size]);
    size++;
    while(que.empty()!=true)
    {   sort(que.begin(),que.end(),mycmp);
   
        node* curr=que.back();
        que.pop_back();
        closed.push_back(curr);
        //===================
        if(compmat(curr->mat,mat2))          //at any instant if current state is equal to final state
        //print the path using backtracking      //किसी भी पल में अगर वर्तमान स्थिति अंतिम स्थिति के बराबर है
        // बैकट्रैकिंग का उपयोग करके पथ प्रिंट क
        { cout<<"printing path"<<endl;
        printpath(curr);
        return ;
         }
       
        int val1=curr->i;
        int val2=curr->j;
        int val3=curr->previ;
        int val4=curr->prevj;
        int hcurr=curr->hval;
            if(issafe(val1+1,val2) &&   val3!=(val1+1) )
            {  
                swap(curr->mat[val1][val2],curr->mat[val1+1][val2]);
                createnode(curr,val1+1,val2,val1,val2,curr->mat);
                swap(curr->mat[val1][val2],curr->mat[val1+1][val2]);
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size])) // check if it is inclosed or not 
                         {  que.push_back(arr[size]);
                           
                            if(compmat(arr[size]->mat,curr->mat))          //at any instant if current state is equal to final state//print the path using backtracking
                            { cout<<"printing path"<<endl;              //किसी भी पल में अगर वर्तमान स्थिति अंतिम स्थिति के बराबर है
                                                                        // बैकट्रैकिंग का उपयोग करके पथ प्रिंट क
                             printpath(arr[size]);
                              return;
                            }
                            size++;
                         }
                else  {delete arr[size] ;}
            
            } 

            if(issafe(val1-1,val2) &&   val3!=(val1-1) )
            {  
                swap(curr->mat[val1][val2],curr->mat[val1-1][val2]);
                createnode(curr,val1-1,val2,val1,val2,curr->mat);
                swap(curr->mat[val1][val2],curr->mat[val1-1][val2]);
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size]))
                        {   que.push_back(arr[size]);
                            if(compmat(arr[size]->mat,curr->mat))          //at any instant if current state is equal to final state//print the path using backtracking
                            { cout<<"printing path"<<endl;                      //किसी भी पल में यदि वर्तमान स्थिति अंतिम स्थिति के बराबर है
                                                                                     //बैकट्रैकिंग का उपयोग करके पथ प्रिंट करें 
                             printpath(arr[size]);
                              return ;}
                              size++;
                         }
                else  {delete arr[size] ;}
            }

            if(issafe(val1,val2-1) &&   val4!=(val2-1) )
            {  
                swap(curr->mat[val1][val2],curr->mat[val1][val2-1]);
                createnode(curr,val1,val2-1,val1,val2,curr->mat);
                swap(curr->mat[val1][val2],curr->mat[val1][val2-1]);
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size]))
                        {  que.push_back(arr[size]);
                            if(compmat(arr[size]->mat,curr->mat))          //at any instant if current state is equal to final state//print the path using backtracking
                            { cout<<"printing path"<<endl;                  //किसी भी पल में अगर वर्तमान स्थिति अंतिम स्थिति के बराबर है
                              printpath(arr[size]);                   // बैकट्रैकिंग का उपयोग करके पथ प्रिंट करें
                             return ;
                            }
                            size++;
                         }
                else  {delete arr[size] ;}
            }
         
          if(issafe(val1,val2+1) &&   val4!=(val2+1) )
            {  
                swap(curr->mat[val1][val2],curr->mat[val1][val2+1]);
                createnode(curr,val1,val2+1,val1,val2,curr->mat);
                swap(curr->mat[val1][val2],curr->mat[val1][val2+1]);
                arr[size]->hval=calheruistic(arr[size],mat2);
                        if(!inclosed(closed,arr[size]))
                        {   que.push_back(arr[size]);
                            if(compmat(arr[size]->mat,curr->mat))          //at any instant if current state is equal to final state//print the path using backtracking
                            { cout<<"printing path"<<endl;             //किसी भी पल में अगर वर्तमान स्थिति अंतिम स्थिति के बराबर है
                             printpath(arr[size]);                       // बैकट्रैकिंग का उपयोग करके पथ प्रिंट करें
                              return ;
                            }
                            size++;
                         }
                else  {delete arr[size] ;}
            }   
    }

}
 
int main() {

    //intial state
    int initial[n][n] =
    {
        {2, 0, 3},
        {1, 8, 4},
        {7, 6, 5}
    };
 
   //final state
    int final[n][n] =
    {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };
    count1=0;
	int x = 0, y = 1;    //position of 0 initially   //शुरुआत में 0 का स्थान
    node * parent =NULL;
    bestfirstsearch(initial, x, y, final ,parent);  // calling bfs  बेस्ट फ्रिस्ट खोज को कॉल करें
    cout<<"Number of states printed "<<count1;  
	return 0;     //आप यह पहले से ही जानते होंगे कि यह क्या है return 0
}