#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
void display(int* arr, int size);
int getMax(int* arr, int size);
void bucketSort(int* arr, int size);
using namespace std;
int getMax(int* arr, int size)
{
	int max=arr[0];
	for(int i=0; i<size; i++)
	{
		if(arr[i]>max)
		max=arr[i];
	}	
	return max;
}
void bucketSort(int* arr, int size) {
  //variables
  int max, bucket = 10, divider, i, j, k;
  
  //10 buckets
  vector<float>B[bucket];

  //find max and min
  max = getMax(arr, size);

  divider = ceil(float(max + 1) / bucket);
  
  //insert element into bucket
  for(i = 0; i < size; i++) {
    j = floor( arr[i] / divider );
    B[j].push_back(arr[i]);
  }
  
  //sort elements in the buckets
  for(i = 0; i < bucket; i++) {
    sort(B[i].begin(), B[i].end());
  }

  //append back the elements from the buckets
  k = 0;
  for(i = 0; i < bucket; i++) {
    for(j = 0; j < B[i].size(); j++) {
      arr[k++] = B[i][j];
    }
  }
}

int main() 
{
 int *arr;
	int n;
	char ch='y';
	do
	{
		cout<<"Enter the number of elements"<<endl;
		cin>>n;
		arr=new int[n];
		cout<<"Enter the elements to be sorted"<<endl;
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<"Before sorting the elements are: "<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<arr[i]<<" ";
		}
		bucketSort(arr,n);
		cout<<endl<<"After sorting the elements are: "<<endl;
		for(int i=0; i<n; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl<<"Do you wish to continue"<<endl;
		cin>>ch;
		if(ch=='y' || ch=='Y')
		{
			delete []arr;
			continue;
		}
		else
			exit(0);
	}while(ch=='y'||ch=='Y');
}

