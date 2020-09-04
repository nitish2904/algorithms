#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> v;
	int s,f;
	forr(int i=0;i<n;i++){
		cin>>s>>f;
		v.push_back(make_pair(s,f));
	}
	sort(v.begin(),v.end(),sortbysec);
	int ans=1;
	for(int i=0;i<n-1;i++){
		if(v[i+1].first>v[i].second)
			ans++;
	}
	cout<<ans<<endl;
}