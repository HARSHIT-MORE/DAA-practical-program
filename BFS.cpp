#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool visited[N];
vector<int> g[N];
int level[N];

void bfs(int s){
	queue<int> q;
	visited[s]=true;
	q.push(s);
	while(!q.empty()){
		int cur_n=q.front();
		q.pop();
		cout<<cur_n<<" ";
		for(int child:g[cur_n]){
			if(!visited[child]){
				q.push(child);
				visited[child]=true;
				level[child]=level[cur_n]+1;
			}
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs(1);

}