#include<iostream>
using namespace std;

struct obj{
	double profit;
	double weight;
	double ratio;
};

void sort(obj o[],int n)
{
	obj temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(o[j].ratio < o[j+1].ratio)
			{
				temp=o[j];
				o[j]=o[j+1];
				o[j+1]=temp;
			}
		}
	}
}

void output(obj o[],int n,int weight)
{
	int rw=weight;
	double totalProfit=0;
	
	cout<<"\tProfit \tWeight \tRatio"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<o[i].profit<<"\t"<<o[i].weight<<"\t"<<o[i].ratio<<endl;
	}
	
	for(int i=0;i<n;i++)
	{
		if(rw!=0)
		{
			if(rw>=o[i].weight)
			{
				totalProfit+=o[i].profit;
				rw-=o[i].weight;
			}else{
				totalProfit+=o[i].ratio*rw;
				rw=0;
			}
		}
	}
	
	cout<<"Total Maximum Profit is :"<<totalProfit<<endl;

}

int main()
{
	int n,max;
	cout<<"\nEnter the total count of weight & profit: ";
	cin>>n;
	obj o[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the profit of "<<i+1<<":";
		cin>>o[i].profit;
		cout<<"\nEnter the weight of "<<i+1<<":";
		cin>>o[i].weight;
		o[i].ratio=o[i].profit/o[i].weight;
	}
	cout<<"\nEnter the Max capacity of Bag: ";
	cin>>max;
	
	sort(o,n);
	output(o,n,max);
	return 0;
}
