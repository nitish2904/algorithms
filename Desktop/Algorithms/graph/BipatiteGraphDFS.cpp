#include<bits/stdc++.h>
using namespace std;
//using dfs and color array to check if a graph is bipartite
//a graph is bipartite when it can be colored using only 2 colors such that no two adjacent nodes have the same color
//a graph with odd length cycle will not be a bipartite graph
bool bipartiteDfs(int start,vector<int> adj[],int &color[]){

    if(color[start] == -1) color[start] = 1;
    for(auto it:adj[start]){
        if(color[it] == -1){
            color[it] = 1 - color[start];
            return bipartiteDfs(it,adj,color);
        }
        else if(color[it] == color[start]){
            return false;
        }
    }

    return true;
}

bool checkBipartite(vector<int> adj[],int n){
    int color[n];
    memset(color,-1,sizeof(color));
    for(int i=0;i<n;i++){
        if(color[i] == -1){
            if(!bipartiteDfs(i,adj,color)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int V,E;
    cin>>V>>E;
    vector<int> adj[V+1];
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<checkBipartite(adj,V)<<endl;
}