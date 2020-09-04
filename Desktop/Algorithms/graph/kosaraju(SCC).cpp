#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>* edges,int start,int* visited,stack<int> &finishStack){
	visited[start]=1;
	for(int i=0;i<edges[start].size();i++){
		if(visited[edges[start][i]]==0){
			dfs(edges,edges[start][i],visited,finishStack);
		}
	}
	finishStack.push(start);
	return;
}
void dfs2(vector<int>* edges,int start,unordered_set<int> *component,int* visited){
	visited[start]=1;
	component->insert(start);
	for(int i=0;i<edges[start].size();i++){
		if(visited[edges[start][i]]==0){
			dfs2(edges,edges[start][i],component,visited);
		}
	}
	return;
}

unordered_set<unordered_set<int>*>* getSCC(vector<int>* edges,vector<int>* edgesT,int n){
	int* visited = new int[n];
	memset(visited,0,sizeof visited);
	stack<int> finishedVertices;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			dfs(edges,i,visited,finishedVertices);
		}
	}
	unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
	int* vis = new int[n];
	memset(visited,0,sizeof vis);
	while(!finishedVertices.empty()){
		int element = finishedVertices.top();
		finishedVertices.pop();
		if(!vis[element]){
			unordered_set<int>* component = new unordered_set<int>();
			dfs2(edgesT,element,component,vis);
			output->insert(component);	
		}
		
	}
	return output;
}
int main(){
	int n;
	cin>>n;
	vector<int>* edges = new vector<int>[n];
	vector<int>*edgesT = new vector<int>[n];
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int j,k;
		cin>>j>>k;
		edges[j-1].push_back(k-1);
		edgesT[k-1].push_back(j-1);
	}
	unordered_set<unordered_set<int>*>* components = getSCC(edges,edgesT,n);
	unordered_set<unordered_set<int>*>::iterator it = components->begin();
	while(it!=components->end() ){
		unordered_set<int>* component = *it;
		unordered_set<int>::iterator it2 = component->begin();
		while(it2!=component->end() ){
			cout<<*it2+1<<" ";
			it2++;
		}
		cout<<endl;
		delete component;
		it++;
	} 
	delete components;
	delete [] edges;
	delete [] edgesT;
}