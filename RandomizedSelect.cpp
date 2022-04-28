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
	swap(a[i],a[r]);
	return partition(a,p,r);
}
int RandomizedSelect(int a[],int p,int r,int i){
	if(p==r)return a[p];
	int q=RandomizedPartition(a,p,r);
	int k=q-p+1;
	if(i==k)return a[q];

	else if(i<k) return RandomizedSelect(a,p,q-1,i);
	else return RandomizedSelect(a,q+1,r,i-k);
}

int main(){
	int n;
	cout<<"Enter number of element of Array: "<<endl;
	cin>>n;
	int A[n];
	
	for(int i=0;i<n;i++){
		cout<<"Enter the element: "<<endl;
		cin>>A[i];
	}
	cout<<"Enter the position: "<<endl;
	int i;
	cin>>i;
	cout<<RandomizedSelect(A,0,n-1,i);


}