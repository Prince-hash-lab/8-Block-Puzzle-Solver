#include<bits/stdc++.h>
using namespace std;
// this is only for numbers 0 to 9 
//  int cal(int a, int b , char c)
//  {
//      if(c=='-') return b-a;
//      if(c=='*') return b*a;
//      if(c=='/') return b/a;
//      if(c=='^') return pow(b,a);
//      if(c=='+') return b+a;
//  }

// int func(string s)
// {
//     stack <int> st;
//     for(int i=0;i<s.length();i++)
//     {
//         if('0'<=s[i] && '9'>=s[i]) st.push(int(s[i])-48);
//         else
//         {     
//             int a=st.top();
//             st.pop();
//             int b =st.top();
//             st.pop();
//             st.push(cal(a,b,s[i]));
//         }
//     }
//     return st.top();
// }

int evaluatePostfix(string exp) 
{ 
    // Create a stack of capacity equal to expression size 
    stack<int> s;
    int i; 
    // s.push((int)(exp[i] - '0'));
    // Scan all characters one by one 
    for (i = 0;i< exp.length(); i++) 
    {  // cout<<" s top is "<<s.top()<<" exp is "<<exp[i]<<endl;

        //if the character is blank space then continue 
        if(exp[i] == ' ')continue; 
          
        // If the scanned character is an 
        // operand (number here),extract the full number 
        // Push it to the stack. 
        else if (isdigit(exp[i])) 
        { 
            int num=0; 
              
            //extract full number 
            while(isdigit(exp[i])) 
            { 
                num = num * 10 + (int)(exp[i] - '0'); 
                i++; 
            } 
            i--; 
            cout<<num<<" ";
              
            //push the element in the stack 
            s.push(num); 
        } 
          
        // If the scanned character is an operator, pop two 
        // elements from stack apply the operator 
        else
        { 
            int val1 = s.top();
            s.pop(); 
            int val2 = s.top(); 
            s.pop();
            cout<<endl<<" val1 and val2 are "<< val1<<" "<<val2<<endl;
            switch (exp[i]) 
            { 
            case '+': s.push(val2 + val1); break; 
            case '-': s.push(val2 - val1); break; 
            case '*': s.push(val2 * val1); break; 
            case '/': s.push(val2/val1); break; 
              
            } 
        } 
    } 
    return s.top(); 
}

int main()
{
    string s="20 3 * 5 +";
    cout<<evaluatePostfix(s);
    return 0;
}
