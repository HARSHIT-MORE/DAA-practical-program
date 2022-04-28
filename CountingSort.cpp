#include<iostream>
using namespace std;

void countingSort(int a[],int b[],int n,int k){
	int c[k+1];
	for(int i=0;i<=k;i++){
		c[i]=0;
	}
	for(int i=0;i<n;i++){
		c[a[i]]+=1;
	}
	for(int i=1;i<=k;i++){
      c[i]=c[i]+c[i-1];
	}
	for(int i=n-1;i>=0;i--){
		b[c[a[i]]-1]=a[i];
		c[a[i]]--;
	}
}
int main(){
	int n;
	cin>>n;
	int a[n],b[n];
	int k=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
        if(a[i]>k){
        	k=a[i];
        }
	}
	cout<<k<<endl;
	countingSort(a,b,n,k);
	for(int i=0;i<n;i++){
		cout<<b[i]<<"  ";
	}

}