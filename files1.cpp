#include <fstream>
#include <cstring>
#include<iostream>
using namespace std;
struct student
{
	char rnum[4];
	char name[10];
	char branch[6];
}s[10];
void pack(ofstream &fout, student &s);
void unpack(ifstream &fin, student &s);
int main()
{

	ofstream fout;
	fout.open("file.txt");
	int n,i;
	i=0;
	cout<<"enter num of students\n";
	cin>>n;
	for (i=0;i<n;i++)
	pack(fout,s[i]);
	fout.close();
	ifstream fin;
	fin.open("file.txt");
	for (int i=0;i<n;i++)
	unpack(fin,s[i]);
	fin.close();
	return 0;
}
void unpack(ifstream &fin, student &s)
{
	while (!fin.eof())
	{
		char a[10];
		fin.getline(a,10,'*');
		cout<<a;
		cout<<" ";
	}
}
void pack(ofstream &fout, student &s)
{ 
	char buffer[100];
	int l,t;
	cout<<"enter name\n";
	cin>>s.name;
	strcpy(buffer,s.name);
	l=strlen(buffer);
	for (int i=l;i<10;i++)
	strcat(buffer,"*");
	cout<<"rollno\n";
	cin>>s.rnum;
	strcat(buffer,s.rnum);
	cout<<"branch\n";
	cin>>s.branch;
	strcat(buffer,s.branch);
	t=strlen(buffer);
	for (int i=t;i<20;i++)
	strcat(buffer,"*");
	fout<<buffer;
}

