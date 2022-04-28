#include<iostream>
using namespace std;

int GetMax(int a[],int n){
	int max=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

void countingSort(int a[],int n,int div){
	int c[10]={0};
	int b[n];
	for(int i=0;i<n;i++){
		c[(a[i]/div)%10]+=1;
	}
	for(int i=1;i<=9;i++){
      c[i]=c[i]+c[i-1];
	}
	for(int i=n-1;i>=0;i--){
		b[c[(a[i]/div)%10]-1]=a[i];
		c[(a[i]/div)%10]--;
	}
	for(int i=0;i<n;i++){
		 a[i]=b[i];
	}
}
void RadixSort(int a[],int n){
	int m=GetMax(a,n);
	for(int div=1;m/div>0;div*=10)
		countingSort(a,n,div);
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
	RadixSort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<"  ";
	}

}