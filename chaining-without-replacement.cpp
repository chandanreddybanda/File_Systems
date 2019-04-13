#include<iostream>
#include<fstream>
using namespace std;
int size=7;
void insert(int a[][4],int ele)
{
	fstream fout;int temp;
	fout.open("linear1.txt");char ch;
	int hashloc=ele%10,loc=hashloc,i=1;
	while(1)
	{
			if(a[loc][0]==0)
			{
				a[loc][1]=ele;
				fout.seekg(loc*7,ios::beg);
				fout<<ele;
				a[loc][0]=1;
			}
			else if(a[loc][0]==1 && a[loc][2]==-1)
			{
					temp=loc;int count=0;
				while(a[loc][0]!=0 && count!=10)
				{
					loc=(loc+1)%10;
					count++;
				}
				if(a[loc][0]==0)
				{
					a[loc][0]=1;
					fout.seekg(loc*7,ios::beg);
					fout<<ele;
					a[temp][2]=loc;
					a[loc][3]=temp;
					break;
				}
			}
			else if(a[loc][0]==1 && a[loc][2]!=-1)
			{
				temp=loc;loc=a[loc][2];int count=0;
				while(a[loc][0]!=0 && count!=10)
				{
					temp=loc;
					loc=a[loc][2];
					count++;
				}
				if(a[loc][0]==0)
				{
					a[loc][0]=1;
					fout.seekg(loc*7,ios::beg);
					fout<<ele;
					a[loc][3]=temp;
					a[temp][2]=loc;
					break;
				}
			}
			return;
		}
}
bool search(int ele,int a[][4])
{
	ifstream fin("linear1.txt");
	int n,loc=ele%10,count=0,temp;
	fin.seekg(loc*size,ios::beg);
	fin>>n;
	if(n==ele)return true;
	else
	{
		count++;
		while(count!=10 && n!=ele)
		{
			if(a[loc][2]!=-1)
			{
				loc=a[loc][2];
				fin.seekg(loc*7,ios::beg);
				fin>>n;
				if(n==ele)
				return true;
				count++;
			}
			else
			{
				loc=(loc+1)%10;
				fin.seekg(loc*7,ios::beg);
				fin>>n;
				if(n==ele)
				return true;
				count++;
			}
		}
		return false;
	}
}
int main()
{
	ofstream fout;
	fout.open("linear1.txt",ios::trunc);
	int n,ch,k,size,s,a[10][4];
	for(int i=0;i<10;i++)
	{
		a[i][0]=a[i][1]=0;
		a[i][2]=a[i][3]=-1;
	}
	ifstream fin;
	for(int i=0;i<10;i++)
	fout<<"*****"<<endl;
	fout.close();
	while(1)
	{
		cout<<"enter element:\n";
		cin>>n;if(n==-1)break;
		insert(a,n);
		cout<<"enter -1 to exit\n";
		cin>>k;
		if(k==-1)
		break;
	}
	cout<<"enter the element to be searched:";
	cin>>s;
	if(search(s,a))cout<<"found!";
	else cout<<"not found:(";
	return 0;
}
