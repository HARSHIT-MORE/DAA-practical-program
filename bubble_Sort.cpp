#include<iostream>
using namespace std;
void bubblesort(int a[],int n){
	for(int i=n-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j]);
			}
		}
	}
}

int main(){
int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	bubblesort(a,n);
	for(int i=0;i<5;i++){
		cout<<a[i]<<"  ";
	}
}