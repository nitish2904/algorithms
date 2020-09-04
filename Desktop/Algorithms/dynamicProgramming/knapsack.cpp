#include<bits/stdc++.h>
using namespace std;
int k[1005][1005];
int knapsack(int* wt,int *val,int n,int W){
	if(n==0||W==0)
		return 0;
	if(k[n][W]!=-1)
		return k[n][W];
	if(wt[n-1]>W){
		k[n][W] = knapsack(wt,val,n-1,W);
		return k[n][W];
	}
	else{
		k[n][W] = max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]),
					knapsack(wt,val,n-1,W));
		return k[n][W];
	}

}
int main(){
    int t;
    cin>>t;
    while(t--){
    	for(int i=0;i<1005;i++)
			for(int j=0;j<1005;j++)
				k[i][j]=-1;
        int N,W;
        cin>>N>>W;
        int* wt = new int[N];
        int* val = new int[N];
        for(int i=0;i<N;i++)
            cin>>val[i];
        for(int i=0;i<N;i++)
            cin>>wt[i];
        cout<<knapsack(wt,val,n,W)<<endl; 
    }
}
