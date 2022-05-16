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
     int level;
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
//बैकट्रैकिंग होने पर प्रत्येक स्तर पर मैट्रिक्स प्रिंट करें
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
    cout<<" heruistic value of  state is "<<a->hval<<endl;
    printMatrix(a->mat);
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
//heuristic taken is level of node + number of correctly placed tiles
// नोड का स्तर + सही ढंग से रखी टाइलों की संख्या को हेयुरिस्टिक मूल्यांकन के रूप में लिया है
int calheruistic(node* Node, int actmat[n][n])
{   int hval=0;
     for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
              if(Node->mat[i][j]==actmat[i][j])
                     hval++;
       
    }
    hval+=Node->level;
    return hval;
}

// for sorting the vector which is taken as priority queue , according to heruistic value
//यह फ़ंक्शन वेक्टर को क्रमबद्ध करने के लिए है जिसे प्राथमिकता कतार के रूप में लिया जाता है, आनुवांशिक मूल्य के अनुसार
bool mycmp(node* one, node* two)
{
    return one->hval < two->hval;
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


void astar(int mat1[n][n],int k , int l, int mat2[n][n],node* parent)
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
    arr[size]->level=0;
    arr[size]->hval=calheruistic(arr[size],mat2);
    que.push_back(arr[size]);
    size++;
    while(que.empty()!=true)
    {    
        vector<node*> temp;
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
        int clvl=curr->level;
            if(issafe(val1+1,val2) &&   val3!=(val1+1) )
            {  
                swap(curr->mat[val1][val2],curr->mat[val1+1][val2]);
                createnode(curr,val1+1,val2,val1,val2,curr->mat);
                swap(curr->mat[val1][val2],curr->mat[val1+1][val2]);
                arr[size]->level=curr->level+1;
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size])) // check if it is inclosed or not 
                         {  temp.push_back(arr[size]);
                           
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
                arr[size]->level=curr->level+1;
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size]))
                        {   temp.push_back(arr[size]);
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
                arr[size]->level=curr->level+1;
                arr[size]->hval=calheruistic(arr[size],mat2);
                if(!inclosed(closed,arr[size]))
                        {  temp.push_back(arr[size]);
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
                arr[size]->level=curr->level+1;
                arr[size]->hval=calheruistic(arr[size],mat2);
                        if(!inclosed(closed,arr[size]))
                        {   temp.push_back(arr[size]);
                            if(compmat(arr[size]->mat,curr->mat))          //at any instant if current state is equal to final state//print the path using backtracking
                            { cout<<"printing path"<<endl;             //किसी भी पल में अगर वर्तमान स्थिति अंतिम स्थिति के बराबर है
                             printpath(arr[size]);                       // बैकट्रैकिंग का उपयोग करके पथ प्रिंट करें
                              return ;
                            }
                            size++;
                         }
                else  {delete arr[size] ;}
            }
            sort(temp.begin(),temp.end(),mycmp);   //sorting children according to heuristic value  बच्चों को हेयुरिस्टिक मूल्य के अनुसार क्रमबद्ध करना
             vector<node*> :: iterator ptr1;        //pointer is initialised here  यहाँ सूचक को आरम्भ किया गया है
   
             for (ptr1 = temp.begin(); ptr1 != temp.end(); ptr1++)
             { 
                que.push_back(*ptr1);       
             }


    }

}
 
int main() {

    //intial state  प्रारंभिक स्थिति
    int initial[n][n] =
    {
        {2, 7, 3},
        {1, 8, 4},
        {0, 6, 5}
    };
 
   //final state अंतिम स्थिति
    int final[n][n] =
    {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
    };
    count1=0;
	int x = 2, y = 0;    //position of 0 initially   //शुरुआत में 0 का स्थान
    node * parent =NULL;
    astar(initial, x, y, final ,parent);  // calling A*  ए* खोज को कॉल करें
    cout<<"Number of states printed "<<count1;  
	return 0;     //आप यह पहले से ही जानते होंगे कि यह क्या है return 0 यदि आप यह नहीं जानते हैं तो आपको शर्म आनी चाहिए
}