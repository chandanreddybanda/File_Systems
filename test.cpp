#include<bits/stdc++.h>
using namespace std;
struct sta
{
	int top=0;
	int ar[50];
};
sta s;
void push(int x)
{
	s.ar[s.top]=x;
	s.top++;
}
float pop()
{
	return s.ar[--s.top];
}
int main()
{
	for(int i=0;i<10;i++)
	{		
		push(i);
	}
	cout<<pop()/pop();
	cout<<pop();
	
}
