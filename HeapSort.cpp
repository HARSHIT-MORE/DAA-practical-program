#include<iostream>
using namespace std;

int size;
void maxHeapify(int a[],int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<size && a[l]>a[largest])
		largest=l;
	if(r<size && a[r]>a[largest])
		largest=r;
	if(largest!=i){
		swap(a[i],a[largest]);
		maxHeapify(a,largest);
	}
}

void BuildMaxHeap(int a[],int n){
	size=n;
	for(int i=n/2-1;i>=0;i--){
		maxHeapify(a,i);
	}
}

void HeapSort(int a[],int n){
	BuildMaxHeap(a,n);
	for(int i=n-1;i>0;i--){
		swap(a[i],a[0]);
		size--;
		maxHeapify(a,0);
	}
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
	HeapSort(A,n);
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
		
	}

}