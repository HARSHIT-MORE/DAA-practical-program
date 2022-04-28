#include<bits/stdc++.h>
using namespace std;

void bucketSort(float a[],int n){
	vector<float> b[n];
	for(int i=0;i<n;i++){
		int bi=n*a[i];
		b[bi].push_back(a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<b[i].size();j++){
			float key=b[i][j];
			int k=j-1;
			while(k>=0 && b[i][j]>key){
				b[i][k+1]=b[i][k];
				k--;
			}
			b[i][k+1]=key;
		}

	}
	int index=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i].size();j++){
			a[index++]=b[i][j];
		}
	}
}

int main(){
float arr[]
		= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}