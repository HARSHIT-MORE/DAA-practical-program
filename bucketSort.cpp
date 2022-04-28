#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void bucketSort(float arr[], int n)
{
	
	vector<float> b[n];

	for (int i = 0; i < n; i++) {
		int bi = n * arr[i];
		b[bi].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++){
		for(int j=1;j<b[i].size();j++)
        {
            int k=j-1;
            float x=b[i][j];
            while(k>=0&&x<b[i][j])
            {
                b[i][k+1]=b[i][k];
                k-=1;
            }
            b[i][k+1]=x;
        }
    }

	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < b[i].size(); j++)
			arr[index++] = b[i][j];
}

int main()
{
	float arr[]
		= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bucketSort(arr, n);

	cout << "Sorted array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}