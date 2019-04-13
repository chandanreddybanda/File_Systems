#include<bits/stdc++.h>
using namespace std;
fstream f[5];
int merg(int a[],int b[],int n,int k)	
{
	int i=0,j=0;
	while(i!=n&&j!=n)
	{
		if(a[i]>b[j])
		f[k]<<b[j++]<<" ";
		else
		f[k]<<a[i++]<<" ";
	}
	if(i==n)
	{
		while(j!=n)
		f[k]<<b[j++]<<" ";
	}
	else if(j==n)
	{
		while(i!=n)
		f[k]<<a[i++]<<" ";
	}
}
int main()
{

	f[0].open("main.txt");
	f[1].open("f1.txt");
	f[2].open("f2.txt");
	f[3].open("f3.txt");
	f[4].open("f4.txt");
	int l=0,k=l, n=3;
	while(f[0])
	{
		int a[n],b[n];
		for(int i=0;i<n;i++)
		f[0]>>a[i];
		for(int i=0;i<n;i++)
		f[0]>>b[i];
		if(l%2==0)
		k=1;
		else
		k=2;
		merg(a,b,n,k);
		l++;
	}
	
}
