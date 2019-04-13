#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream f1,f2;
	f1.open("f1.txt");
	f2.open("f2.txt");
	int a[200],i=0;
	while(f1)
	{
		f1>>a[i];
		i++;
	}i=i-1;
	int b[200];
	while(f2)
	{
		f2>>a[i];
		i++;
	}i=i-1;
	sort(a,a+i);
	for(int j=0;j<i;j++)
	cout<<a[j]<<" ";
}
