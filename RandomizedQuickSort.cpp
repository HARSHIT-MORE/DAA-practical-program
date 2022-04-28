#include<iostream>
using namespace std;
int partition(int a[],int p,int r){
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		if(a[j]<=x){
			i=i+1;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}
int RandomizedPartition(int a[],int p,int r){
	int i=rand()%(r-p+1);
	cout<<i<<endl;
	swap(a[i],a[r]);
	return partition(a,p,r);
}

void RandomizedQuickSort(int a[],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		RandomizedQuickSort(a,p,q-1);
		RandomizedQuickSort(a,q+1,r);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	RandomizedQuickSort(a,0,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}

}
