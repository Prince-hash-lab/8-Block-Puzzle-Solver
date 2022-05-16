#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define debug(x) cout<<#x<<" = "<<x<<endl;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.second == b.second)
	{
        return (a.first/a.second)<(b.first/b.second);
		
	}
	else return a.second>b.second;
}

int main()
{
    int minMarks, S, N;
    cin >> minMarks >> S >> N;
    vector<int> s;//storing Si students initial marks;
    for(int i=0, x; i<S; i++)
    {
        cin >> x;
        s.push_back(x);
    } 
    // to store the max Score and the subquery corresponding
     vector<pair<int,int>> temp ;
    vector<pair<int,int>> original;
    while(N--)
    {
        int maxScore, subQuery;
        cin >> maxScore >> subQuery;
        temp.push_back(make_pair(maxScore,subQuery));
        original.push_back(make_pair(maxScore,subQuery));
        
       
    }
    // make a pair vector for sorting
   
   
    //now sort the vec using comparator
    sort(temp.begin(), temp.end(), cmp);

    //ab hamaare paas temp hai vector with pair elemeents sorted according to the second element
    //iterator for students array vector s
  for(auto x : temp)
    {
    	cout<<x.first<<" "<<x.second<<endl;
	}
	for(auto x : original)
    {
    	cout<<x.first<<" "<<x.second<<endl;
	}
//s array 
	vector<int> index;
	for(int i=0; i<temp.size(); i++)
	{
		for(auto it = original.begin(); it!=original.end(); it++)
		{
			if((it->first == temp[i].first)&& (it->second == temp[i].second))
			{
				int loc = it - original.begin();
				index.push_back(loc+1);
                break;
			}

		}
	}
	
	for(auto x : index)
	{
		cout<<x<<" ";
	}
	int i = 0;
	while(i<S)
	{
		int init = s[i];
		vector<int> ans ;
		for(int j = 0,k=0; j< temp.size(); j++)
		{
			if(init < minMarks)
			{
				init += temp[j].first;
				ans.push_back(index[k++]);
			}
		}
		i++;
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<" ";
		for(auto x : ans)
		{
			cout<<x<<" ";
		}
		cout<<"\n";
		
	}

	
}