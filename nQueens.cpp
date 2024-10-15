#include<iostream>
#include<cmath>
using namespace std;
int board[20],count=1;

void print(int n)
{
	cout<<"\nSolution: "<<count++<<":\n\n";

	for(int i=1;i<=n;i++)
	{
		cout<<"\t"<<i;
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<"\n\n"<<i;
		for(int j=1;j<=n;j++)
		{
			if(board[i]==j)
			{
				cout<<"\tQ";
			}else{
				cout<<"\t--";
			}
		}
	}	
}

bool place(int row,int col)
{
	for(int i=1;i<row;i++)
	{
		if(board[i]==col || abs(board[i]-col)==abs(i-row))
		{
			return false;
		}
	}
	return true;
}

void queen(int row,int n)
{
	for(int col=1;col<=n;col++)
	{
		if(place(row,col))
		{
			board[row]=col;
			if(row==n)
			{
				print(n);
			}else{
				queen(row+1,n);
			}
		
		}
	}
}

int main()
{
	cout<<"\nEnter the Number of Queens: ";
	int n;
	cin>>n;
	
	queen(1,n);
	return 0;
}
