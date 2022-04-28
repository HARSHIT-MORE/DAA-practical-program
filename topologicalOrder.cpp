#include<bits/stdc++.h>
using namespace std;

void topologicalOrdering(vector<int> adj[],bool visited[],stack<int> &stk,int s){
	visited[s]=true;
	for(int child:adj[s]){
		if(visited[child]) continue;
		topologicalOrdering(adj,visited,stk,child);
	}
	stk.push(s);
}
int main(){
 int n,m;
 cin>>n>>m;
 vector<int> adj[n];
 bool visited[n];
 stack<int> s;
 for(int i=0;i<n;i++){
 	visited[i]=false;
 }
 for(int i=0;i<m;i++){
 	int u,v;
 	cin>>u>>v;
    adj[u].push_back(v);
 }
 for(int i=0;i<n;i++){
 	if(!visited[i])
 		topologicalOrdering(adj,visited,s,i);
 }
 for(int i=0;i<n;i++){
 	cout<<s.top()<<"  ";
 	s.pop();
 }
}