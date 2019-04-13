#include<iostream>
#include<fstream>
using namespace std;
int size=7;
void insert(int el)
{
	fstream fout;
	fout.open("linear.txt");char ch;
	int hashloc=el%10,loc=hashloc,i=1;
	while(1)
	{
		fout.seekg(loc*size,ios::beg);
		fout>>ch;
		if(ch=='*')
		{
			fout.seekp(loc*size,ios::beg);
			fout<<el;fout.close();return;
		}
		loc=(hashloc+i)%10;i++;
	}
}
bool search(int ele)
{
	ifstream fin("linear.txt");
	int n,loc=ele%10,count=0;
	fin.seekg(loc*size,ios::beg);
	fin>>n;
	if(n==ele)return true;
	else
	{
		while(count!=10)
		{
			loc=(loc+1)%10;
			fin.seekg(loc*size,ios::beg);
			fin>>n;
			if(n==ele)
			return true;
			count++;
		}
		return false;
	}
}
int main()
{
	ofstream fout;
	fout.open("linear.txt",ios::trunc);
	int n,ch,k,size,s;
	ifstream fin;
	for(int i=0;i<10;i++)
	fout<<"*****"<<endl;
	fout.close();
	while(1)
	{
		cout<<"enter element:\n";
		cin>>n;if(n==-1)break;
		insert(n);
		cout<<"enter -1 to exit\n";
		cin>>k;
		if(k==-1)
		break;
	}
	cout<<"enter the element to be searched:";
	cin>>s;
	if(search(s))cout<<"found!";
	else cout<<"not found";
	return 0;
}
