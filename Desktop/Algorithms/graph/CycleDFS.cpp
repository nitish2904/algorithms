#include<bits/stdc++.h>
using namespace std;

bool check(int start,int parent, vector<int>&visited, vector<int> adj[]){
    visited[start] = true;
    for(auto it : adj[start]){
        if(!visited[it]){
            if(check(it,start,visited,adj)) return true;

        }
        else{
            if(it != parent) return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    vector<bool> visited(V+1,false);
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            if(check(i,V,adj,visited)) return true;
        }
    }
    return false;
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
    //function to detect cycle in a graph
    bool flag = isCycle(V,adj);
        cout<<flag<<endl;
    return 0;
}