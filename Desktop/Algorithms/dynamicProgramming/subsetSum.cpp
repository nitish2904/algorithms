#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
bool subset(int *a,int sum,int n){
    if(n<0)
        return false;
    if(sum<0)
        return false;
    if(sum==0 && n>=0)
        return true;
    if(dp[n][sum]!=-1)
        return dp[n][sum];
	bool including = subset(a,sum-a[n],n-1);
    bool excluding = subset(a,sum,n-1);
    dp[n][sum]=including||excluding;
  	return dp[n][sum];
    
}
int main()
{	
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++)
            dp[i][j]=-1;
    }
    int n;
    cin>>n;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    bool ans = subset(a,k,n-1);
    if(ans)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
