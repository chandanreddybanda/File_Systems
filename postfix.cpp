#include<bits/stdc++.h>
using namespace std;
struct sta
{
	int top=-1;
	int ar[50];
};
sta s;
float puch(float x)
{
		s.top++;
		s.ar[s.top]=x;
}
float pop()
{
	return s.ar[s.top--];
}
int main()
{
	string c;
	cin>>c;
	for(int i=0;i<c.length();i++)
	{
		if(int(c[i])>47 && int(c[i])<58)
		{
			puch(int(c[i])-48);
		}
		else if(c[i]=='*')
		{
			puch(pop()*pop());
		}
		else if(c[i]=='+')
		{
			puch(pop()+pop());
		}
		else if(c[i]=='-')
		{
			puch(-(pop()-pop()));
		}
		else if(c[i]=='/')
		{	
			puch(1/(pop()/pop()));
		}
	}
cout<<pop();
}
