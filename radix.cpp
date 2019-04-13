#include<bits/stdc++.h>
using namespace std;
struct s
{
	int front=-1;
	int rear=-1;
	int elem[100];
};
s q[10];
void push(int x,int z)
{
	q[z].front++;
	q[z].elem[q[z].front]=x;
}
int pop(int y)
{
	while(q[y].rear!=q[y].front && q[y].front>=0)
	{
		q[y].rear++;q[y].front=-1;
		push(q[y].elem[q[y].rear],(q[y].elem[q[y].rear]/10)%10);
	}	
	q[y].rear=-1;
	while(q[y].rear!=q[y].front && q[y].front>=0)
	{
		q[y].rear++;
		cout<<q[y].elem[q[y].rear]<<" ";
	}

}
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
	{
		cin>>a[i];
		push(a[i],a[i]%10);
	}
	for(int i=0;i<10;i++)
	{
		pop(i);
	}
}
// 173 5 59 234 8 871 36 65 105 86
