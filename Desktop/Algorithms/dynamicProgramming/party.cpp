#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,pb,ef[101],fun[101];
	while(1){
		memset(ef,0,sizeof(ef));
		memset(fun,0,sizeof(fun));
		cin>>pb>>n;
		if(pb==0 && n==0)
			break;
		for(int i=0;i<n;i++)
			cin>>ef[i]>>fun[i];
		int dp[101][101];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=pb;j++){
				if(ef[i-1]>j)
					dp[i][j]=dp[i-1][j];
				else{
					dp[i][j]=max(dp[i-1][j],fun[i-1]+dp[i-1][j-ef[i-1]]);

				}
			}
		}
		int maxfun=dp[n][pb];
		int min=0;
		for(int i=0;i<=pb;i++){
			if(dp[n][i]==maxfun){
				min=i;
			}
		}
		cout<<min<<" "<<maxfun<<endl;
	}

}