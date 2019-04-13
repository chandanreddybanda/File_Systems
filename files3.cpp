#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct a
{
	char hno[4];
	char cityno[4];
	
}a1;
union u
{
  struct a a1;
  char mnum[10];
}u1;
struct student
{
	int tag;
	union u u1;
	char rnum[4];
	char name[10];
}s[10];
void pack(ofstream &fout,student &s)
{
	char *buffer,a[10];
	buffer=new(char[100]);
	int x,y;
	cout<<"name\n";
	cin>>s.name;
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	cout<<"rnum\n";
	cin>>s.rnum;
	strcat(buffer,s.rnum);
	strcat(buffer,"|");
	cout<<"1.hno/cityno 2.mobile num\n";
	cin>>s.tag;
	if (s.tag==1)
	{
		cout<<"enter hno\n";
		cin>>s.u1.a1.hno;
		strcat(buffer,s.u1.a1.hno);
		strcat(buffer,"|");
		cout<<"enter cityno\n";
		cin>>s.u1.a1.cityno;
		strcat(buffer,s.u1.a1.cityno);
		strcat(buffer,"#");
		
	}
	if (s.tag==2)
	{
		cout<<"enter mobile num\n";
		cin>>s.u1.mnum;
		strcat(buffer,s.u1.mnum);
		strcat(buffer,"#");
	}
	
	fout<<buffer;
}
void unpack(ifstream &fin,student &s)
{
	while (!fin.eof())
	{
	char a[100];
	fin.getline(a,100,'|');
	cout<<a;
	cout<<"  ";
}
	
}
int main()
{
	ofstream fout;
	fout.open("file2.txt");
	int n;
	cout<<"num of students\n";
	cin>>n;
	for (int i=0;i<n;i++)
	pack(fout,s[i]);
	fout.close();
	ifstream fin("file2.txt");
	for (int i=0;i<n;i++)
	unpack(fin,s[i]);
	fin.close();
}
