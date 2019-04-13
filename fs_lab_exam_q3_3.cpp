#include<iostream>
#include<fstream>
using namespace std;
void merg(int m[],int n[],fstream f3)
{
	int x=0,y=0;
	while(1)
	{
		if(m[x]>n[y])
		{
			f3<<n[y]<<" ";
			y++;
			if(n[y]==-1)
			break;
		}
		else
		{
			f3<<m[x]<<" ";
			x++;
			if(m[x]==-1)
			break;
		}
	}
	if(m[x]!=-1)
	{
		while(m[x]!=-1)
		f3<<m[x++]<<" ";
	}
	if(n[y]!=-1)
	{
		while(n[y]!=-1)
		f3<<n[y++]<<" ";
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
	int m[10],n[10];
	fstream f;
	f.open("f3.txt");
	for(int i=0;i<x/2;i++)
	{
		for(int j=0;j<10;j++)
		m[j]=a[i][j];
		for(int j=0;j<10;j++)
		n[j]=a[i+2][j];
		merg(m,n,f);
	}
	f1.close();
	f2.close();
	f.close();
}
