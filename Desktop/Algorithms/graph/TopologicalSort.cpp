void topologicalSort(int start,bool visited[],stack<int> &Stack){
	visited[start]=true;
	for(int i=0;i<adj[start].size();i++){
		if(!visited[adj[start][i]]){
			topologicalSort(adj[start][i],visited,stack);
		}

	}
	Stack.push(start);
}
void printTopologicalSort(){
	stack<int>Stack;
	bool* visited = new bool[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int i=0;i<v;i++)
		if(!visited[i])
			topologicalSort(i,visited,Stack);
	while(Stack.empty()==false){
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}