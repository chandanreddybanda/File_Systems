#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream f1;
	f1.open("m1q1f1.txt");
	int a[100],i=0;
	while(f1)
	{
		f1>>a[i];
		i++;
	}
	f1.close();
	ofstream f2;i--;
	f2.open("m1q1f2.txt");
	for(int j=0;j<i-1;j++)
	{
		int l=a[j];
		int k=a[++j];
		for(int m=0;m<k;m++)
		{
			f2<<l;
			f2<<'-';
			f2<<a[++j];
			f2<<endl;
		}
		f2<<endl;
	}
}
