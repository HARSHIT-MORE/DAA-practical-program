#include<iostream>
using namespace std;

int HoarePartition(int a[],int p,int r){
	int x=a[p];
	int i=p-1;
	int j=r+1;
	while(true){
		do{
			i++;
		}while(a[i]<x);
		do{
			j--;
		}while(a[j]>x);
		if(i>=j) return j;
		swap(a[i],a[j]);
	}
}
void QuickSort(int a[],int p,int r){
	if(p<r){
		int q=HoarePartition(a,p,r);
		QuickSort(a,p,q);
		QuickSort(a,q+1,r);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	QuickSort(a,0,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}

}
