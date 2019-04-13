#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct student
{
	char *name;
	char *rno;
	char *branch;
}s[10];
void pack(ofstream &fout,student &s)
{
	char *buffer;
	buffer=new(char[100]);
	s.name=new(char[10]);
	s.rno=new(char[10]);
	s.branch=new(char[10]);
	cout<<"Enter name\n";
	cin>>s.name;
	strcpy(buffer,s.name);
	strcat(buffer,"|");
	cout<<"rno.\n";
	cin>>s.rno;
	strcat(buffer,s.rno);
	strcat(buffer,"|");
	cout<<"Branch\n";
	cin>>s.branch;
	strcat(buffer,s.branch);
	strcat(buffer,"|");
	strcat(buffer,"#");
	fout<<buffer;
	
}
void unpack(ifstream &fin,student &s)
{
	while (!fin.eof())
	{
		char a[100];
		fin.getline(a,100,'|');
		cout<<a;
		cout<<" ";
		
	}
}
int main()
{
	ofstream fout;
	fout.open("file1.txt");
	int n;
	cout<<"num of students\n";
	cin>>n;
	for (int i=0;i<n;i++)
	pack(fout,s[i]);
	fout.close();
	ifstream fin("file1.txt");
	for (int i=0;i<n;i++)
	unpack(fin,s[i]);
	fin.close();
	
}
