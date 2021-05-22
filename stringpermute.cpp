#include <bits/stdc++.h>
using namespace std;

void func(string s,int i,int n)
{   cout<<endl<<i<<endl;
    if(s.length()==0) return ;
    if(i==n) {cout<<s<<" "<<i<<" "; return;} 
    func(s,i+1,n);
    swap(s[i],s[i+1]);
    func(s,i+1,n);
    swap(s[i],s[i+1]);
    
}

int main() {
	func("abc",0,3);
	return 0;
}