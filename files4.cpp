#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;
struct children
{
	char cname[10];
	char dob[10];
	
};
struct employee
{char empname[10];
char empid[10];
int child;
children c[10];
};
void pack(ofstream &fout,employee &emp)
{ char *buffer;
buffer=new (char[100]);
char a[10];
int x,y;
cout<<"enter name:";
cin>>emp.empname;
strcpy(buffer,emp.empname);
strcat(buffer,"|");
cout<<"enter empid:";
cin>>emp.empid;
strcat(buffer,emp.empid);
strcat(buffer,"|");
cout<<"no.of children:";
cin>>emp.child;
x=emp.child;
itoa(emp.child,a,10);
strcat(buffer,a);
strcat(buffer,"|");
cout<<"enter children details:";
cout<<"name,dob\n";
for(int i=0;i<x;i++)
{ cin>>emp.c[i].cname;
cin>>emp.c[i].dob;
strcat(buffer,emp.c[i].cname);
strcat(buffer,"|");
strcat(buffer,emp.c[i].dob);
strcat(buffer,"|");
}
strcat(buffer,"#");
fout<<buffer;
}
void unpack(ifstream &fin,employee &emp)
{ char *buffer,a[20];
buffer=new(char[100]);
int i=0,j;
fin.getline(buffer,100,'#');
for(int k=0;k<3;k++)
{j=0;
while(buffer[i]!='|')
{a[j]=buffer[i];
i++;
j++;
}
a[j]='\0';
i++;
if(k!=2)
cout<<a<<" ";
else
emp.child=atoi(a);
}
cout<<"\n no.of children:"<<emp.child<<endl;
for(int l=0;l<emp.child;l++)
{for(int k=0;k<2;k++)
{j=0;
while(buffer[i]!='|')
{a[j]=buffer[i];
i++;
j++;
}
a[j]='\0';
i++;
cout<<a<<" ";
}
cout<<endl;
}
}
int main()
{ employee emp[10];
ofstream fout;
fout.open("file4.txt");
int n;
cout<<"no.of employees:";
cin>>n;
for(int i=0;i<n;i++)
pack(fout,emp[i]);
fout.close();
ifstream fin;
fin.open("file4.txt");
cout<<"\n employee detailds";
for(int i=0;i<n;i++)
{cout<<endl;
unpack(fin,emp[i]);
}
}
