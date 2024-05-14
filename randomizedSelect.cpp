#include<iostream>
#include<ctime>
using namespace std;
void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
int partition(int *arr, int p, int r)
{
	int x=arr[r];
	int i=p-1;
	for(int j=p; j<r; j++)
	{
	
		if(arr[j]<x)
		{
			i=i+1;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[r]);
	return i+1;
}
int randomizedPartition(int *arr,int p,int r)
{
		//srand(time(NULL));
		int i = p+rand()%(r-p);
		swap(arr[i],arr[r]);
		return partition(arr,p,r);
		
}
int randomizedSelect(int* arr, int p, int r, int i)
{
	if(p==r)
		return arr[p];
	int q=randomizedPartition(arr, p, r);
	int k=q-p+1;
	if(i==k)
		return arr[q];
	else if(i<k)
		return randomizedSelect(arr,p,q-1,i);
	else
		return randomizedSelect(arr, q+1, r, i-k);
		
}
int main()
{
	int *arr;
	int size, i;
	char ch='y';
	do
	{
		cout<<"Enter the size of the array"<<endl;
		cin>>size;
		arr=new int[size];
		cout<<"Enter the array"<<endl;
		for(int j=0; j<size; j++)
		{
			cin>>arr[j];
		}
		cout<<"which smallest element do you wish to retrieve ?"<<endl;
		cin>>i;
		int small=randomizedSelect(arr,0,size-1,i);	
		cout<<"The "<<i<<"th smallest element is: "<<small<<endl;
		cout<<"Do you wish to continue"<<endl;
		cin>>ch;
		if(ch=='y' || ch== 'Y')
		{
			delete [] arr;
			continue;
		}
		else 
			exit(0);
    }while(ch=='y' || ch=='Y');
}
