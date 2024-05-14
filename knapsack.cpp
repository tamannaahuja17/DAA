#include<iostream>
using namespace std;

int dp[1001][1001];
int calMax(int a, int b)
{
	if(a<b)
		return b;
	else 
		return a;
}
int solve(int* wt, int *val, int w, int n)
{
	if(w==0 or n==-1)
		return 0;
	if(dp[n][w]!=-1)
		return dp[n][w];
	if(wt[n]>w)
	{
		return dp[n][w]=solve(wt,val,w,n-1);
	}
	int a,b;
	a=val[n]+solve(wt,val,w-wt[n],n-1);
	b=solve(wt,val,w,n-1);
	return dp[n][w]=calMax(a,b);	
}
int knapSack(int W, int* wt, int* val, int n)
{
	dp[n][W];
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<W; j++)
		{
			dp[i][j]=-1;
		}
	}	
	return solve(wt,val,W-1,n-1);
}
int main()
{
	int W, n;
	int* val;
	int* wt;
	cout<<"Enter the weight of the knapsack"<<endl;
	cin>>W;
	cout<<"Enter the number of objects"<<endl;
	cin>>n;
	val=new int[n];
	wt=new int[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Enter the value of object "<<i+1<<endl;
		cin>>val[i];
		cout<<"Enter the weight of object"<<i+1<<endl;
		cin>>wt[i];
	}
	 int maximum=knapSack(W, wt, val, n);
	 cout<<"Maximum profit is: "<<maximum;
}
