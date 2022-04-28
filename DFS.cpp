#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

bool visited[N];
vector<int> g[N];

void dfs(int v){
	visited[v]=true;
		cout<<v<<" ";
	
	// cout<<v<<" ";
	for(int child:g[v]){
		if(visited[child]) continue;
		dfs(child);
	}
}

int main(){
int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		// g[y].push_back(x);
	}
	dfs(1);
}