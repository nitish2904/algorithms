#include<bits/stdc++.h>
using namespace std;
int countWaysToMakeChange(int denominations[], int m, int n){
	int table[m+1][n+1];
	//m is no. of denominatons 
	// n is the value of sum.
	memset(table,0,sizeof(table));
	for(int i=0;i<=m;i++)
		table[i][0]=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			//if denomination is larger than the sum.
			if(denominations[i-1]>j)
				table[i][j]=table[i-1][j];
			else{
				//taking both combinations 1.without the ith denominations and 2.with the ith denominations
				//gfg has wrong and confusing solution donot go there :)
				table[i][j]=table[i-1][j] + table[i][j-denominations[i-1]];
			}
		}
	}
	for(int i=0;i<=m;i++){
		cout<<endl;
		for(int j=0;j<=n;j++)
			cout<<table[i][j]<<" ";
	}
	cout<<endl;
	return table[m][n];

}
int main(){
	int s[] = {1,2,3};
	cout<<endl<<countWaysToMakeChange(s,3,5);
}

