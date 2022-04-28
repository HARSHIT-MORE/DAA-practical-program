#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int l[n1+1];
	int r1[n2+1];
	for(int i=0;i<n1;i++){
		l[i]=a[p+i];
	}
	for(int j=0;j<n2;j++){
		r1[j]=a[q+j+1];
	}
	l[n1]=INT_MAX;
	r1[n2]=INT_MAX;
	int i=0,j=0;
	for(int k=p;k<=r;k++){
		if(l[i]<=r1[j]){
			a[k]=l[i];
			i++;
		}
		else{
			a[k]=r1[j];
			j++;
		}
	}

}
void merge_sort(int a[],int p,int r){
	if(p==r){
       return;
	}

		int q=(p+r)/2;
	    merge_sort(a,p,q);
	    merge_sort(a,q+1,r);
	    merge(a,p,q,r);
}

int main(){
    int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	merge_sort(a,0,5);
	for(int i=0;i<5;i++){
		cout<<a[i]<<"  ";
	}
}