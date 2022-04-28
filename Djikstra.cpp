#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10;

vector<int> dijikstra(vector<pair<int,int>> adj[],int n,int source){
	vector<int> visited(n,0);
	vector<int> dist(n,INF);

	set<pair<int,int>> st;
	st.insert({0,source});
	dist[source]=0;
	while(st.size()>0){
		auto node=*st.begin();
		int v=node.second;
		int dist_v=node.first;
		st.erase(st.begin());
		if(visited[v]) continue;
		visited[v]=1;
		for(auto child:adj[v]){
			int child_v=child.first;
			int wt=child.second;
			if(dist[v]+wt<dist[child_v]){
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}
		}
	}
	return dist;
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> adj[n];
	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		adj[x].push_back({y,wt});
	}
	vector<int> distance=dijikstra(adj,n,0);
	for(int i=0;i<n;i++){
		cout<<i+1<<"  "<<distance[i]<<endl;
	}
}