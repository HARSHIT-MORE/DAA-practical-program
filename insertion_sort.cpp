#include<iostream>
using namespace std;

void insertionSort(int a[],int n){
	for(int j=1;j<n;j++){
		int key=a[j];
		int i=j-1;
		while(i>=0 && a[i]>key){
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	insertionSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}

}