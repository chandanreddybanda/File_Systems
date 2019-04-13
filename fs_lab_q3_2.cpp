#include<bits/stdc++.h>
using namespace std;
void shuffle(int a[],int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int least(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(a[i]<a[i+1])
		swap(a[i],a[i+1]);
	}
	return a[n-1];
}
int merg(int a[][10],int x)
{
	int b[x];
	for(int i=0;i<x;i++)
	{
		b[i]=a[i][0];
	}
	int t=least(b,x),index;
	for(int i=0;i<x;i++)
	{
		if(a[i][0]==t)
		{
			a[i][0]=-1;
			for(int i=0;i<x;i++)
			{
				b[i]=a[i][0];
			}
			shuffle(b,x);
		}
	}
}
int main()
{
	ifstream f1,f2;
	f1.open("f1.txt");
	f2.open("f2.txt");
	int a[10][10],x=0,y=0,t;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		a[i][j]=-1;
	}
	f1>>a[x][y++];
	while(f1)
	{
		f1>>t;
		if(a[x][y-1]<t)
		a[x][y++]=t;
		else
		{
			y=0;
			a[++x][y++]=t;
		}
	}y=0;
	while(f2)
	{
		f2>>t;
		if(a[x][y-1]<t)
		a[x][y++]=t;
		else
		{
			y=0;
			a[++x][y++]=t;
		}
	}
	merg(a,x);
}
