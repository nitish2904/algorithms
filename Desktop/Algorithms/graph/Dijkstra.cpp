#include <iostream>
using namespace std;
int getMinVertex(bool* visited,int* weight,int n){
	int minvertex= -1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minvertex==-1 || weight[minvertex]>weight[i])){
			minvertex = i;
		}
	}
	return minvertex;
}
void Dijkstra(int** edges,int n){
	bool* visited = new bool[n];
	int* dist = new int[n];

	for(int i=0;i<n;i++){
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	for(int i=0;i<n-1;i++){
		//get minvertex i.e. unvisited vertex with minimum weight
		int minvertex = getMinVertex(visited,dist,n);
		visited[minvertex]=true;
		//explore all the neighbours of the minimum vertex and update
		for(int j=0;j<n;j++){
			if(edges[minvertex][j]!=0 && !visited[j]){
				if(dist[j]>dist[minvertex]+edges[minvertex][j]){
					dist[j]=dist[minvertex]+edges[minvertex][j];
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		cout<<i<<" "<<dist[i]<<endl;
	}
}
int main()
{
  	int n, E, tempX, tempY;
  	cin >> n >> E;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
    	edges[i]=new int[n];
    	for(int j=0;j<n;j++)
    		edges[i][j]=0;
    }
    for(int i=0;i<E;i++){
    	int f,s,weight;
    	cin>>f>>s>>weight;
    	edges[f][s]=weight;
    	edges[s][f]=weight;
    }
    cout<<endl;
    prims(edges,n);
  
  return 0;
}
