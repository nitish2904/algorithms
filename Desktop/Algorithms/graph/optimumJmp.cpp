#include<bits/stdc++.h>
using namespace std;
//dijkstra approach for optimum jump
int solve(vector<int>arr,int n){
	if(n==1)
		return arr[0];

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	vector<bool>visited(n,false);
	vector<int>dist(n,-1);
	pq.push({0,0});
	dist[0]=0;

	for(int c=0;c<n-1;c++){
		int u = pq.top().second;
		pq.pop();
		visited[u]=true;

		if(u+2 < n && !visited[u+2] && (dist[u+2]==-1 || dist[u]+arr[u]<dist[u+2])){
			dist[u+2] = dist[u]+arr[u];
			pq.push({dist[u+2],u+2});
		}
		if(u-1>=0 && !visited[u-1] && (dist[u-1]==-1 ||dist[u]+arr[u]<dist[u-1])){
			dist[u-1]=dist[u]+arr[u];
			pq.push({dist[u-1],u-1});
		}
	}
	return min(dist[n-1]+arr[n-1],dist[n-2]+arr[n-2]);

}
int main(){
	int n;
	cin>>n;
	vector<int>arr;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}
	cout<<solve(arr,n);
}
