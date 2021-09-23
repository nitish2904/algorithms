#include<bits/stdc++.h>
using namespace std;

bool check(int start,int V,vector<int> adj[],vector<bool> &visited){
    //mark this node as visited
    visited[start] = true;
    //we will be using bfs approach here to detect cycle in a graph
    queue<pair<int,int>>q;
    q.push({start,-1}); //since it is a start node so it doesnot have a parent rest will have a parent

    while(!q.empty()){

        int current = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it : adj[current]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it,current});
            }
            else if(parent != it) //if a node has more than one parent then there is a cycle
                return true;
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