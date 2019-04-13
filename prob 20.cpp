#include<iostream>
using namespace std;
int main()
{
	for(int i=1;i<15;i++)
	{
		long long int k=1;
		for(int j=1;j<i+1;j++)
		{
			k=k*j;
		}
		cout<<k<<" ";
	}
}
