#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int wt[N];
int val[N];
int dp[105][10005];

int knapsack(int index,int wt_left){
	if(wt_left==0)return 0;
	if(index<0) return 0;
    if(dp[index][wt_left]!=-1) return dp[index][wt_left];
	int ans=knapsack(index-1,wt_left);
	if(wt_left-wt[index]>=0)
		ans=max(ans,knapsack(index-1,wt_left-wt[index])+val[index]);
    return dp[index][wt_left]=ans;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>wt[i]>>val[i];
	}
	cout<<knapsack(n-1,w)<<endl;


}