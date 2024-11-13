#include<iostream>
using namespace std;

int dynamic(int n,int cap,int weight[],int profit[])
{
	int ans[n+1][cap+1];
	for(int i=0;i<=n;i++)
	{
		for(int w=0;w<=cap;w++)
		{
			if(i==0 || w==0)
			{
				ans[i][w]=0;
			}else if(weight[i-1]<=w)
			{
				ans[i][w]=max(ans[i-1][w],profit[i-1]+ans[i-1][w-weight[i-1]]);
			}else{
				ans[i][w]=ans[i-1][w];
			}
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<cap;j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return ans[n][cap];
}

int main()
{
	int obj,cap;
	cout<<"\nEnter the Total Count of Objects: ";
	cin>>obj;
		
	cout<<"\nEnter the Capicity: ";
	cin>>cap;
	
	int weight[obj],profit[obj];
	cout<<"\nEnter the Details: ";
	for(int i=0;i<obj;i++)
	{
		cout<<"Object "<<i+1<<" :Weight,Profit ";
		cin>>weight[i]>>profit[i];
	}
	
	int maxProfit=dynamic(obj,cap,weight,profit);
	cout<<"\nFinal Maximum Profit is: "<<maxProfit;
	return 0;
}
