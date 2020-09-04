#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005]={0};
int lcs(string s1,string s2,int m,int n){
	if(m==s1.length()||n==s2.length())
		return 0;
	if(dp[m+1][n+1]>-1)
		return dp[m+1][n+1];
	if(s1[m]==s2[n])
		return dp[m+1][n+1]=1+lcs(s1,s2,m+1,n+1);
	else
		return dp[m+1][n+1]=max(lcs(s1,s2,m,n+1),lcs(s1,s2,m+1,n));
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<=s1.length();i++){
		for(int j=0;j<=s2.length();j++)
			dp[i][j]=-1;
	}
	cout<<lcs(s1,s2,0,0);
}