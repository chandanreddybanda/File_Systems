#include<bits/stdc++.h>
#include<fstream>
#include<cmath>
#include<algorithm>
using namespace std;
int allempty(ifstream in[4])
{
	for(int j=0;j<4;j++)
	{
		if(!in[j].eof())
		{
			return 0;
		}
		in[j].close();
	}
	return 1;
}
int main()
{
	ifstream in;
	in.open("main.txt");
	ofstream out[8];
	out[0].open("f0.txt");
	out[1].open("f1.txt");
	out[2].open("f2.txt");
	out[3].open("f3.txt");
	out[4].open("f4.txt");
	out[5].open("f5.txt");
	out[6].open("f6.txt");
	out[7].open("f7.txt");
	int check=0,checkcn;
	while(!in.eof())
	{
		in>>checkcn;
		check++;
	}
	in.close();
	int w=0;
	while(3*pow(4,w)<check)
	w++;
	ofstream out3;
	out3.open("main.txt",ios::app);
	while(check!=3*pow(4,w))
	{
		out3<<" "<<1000;
		check++;
	}
	out3.close();
	in.open("main.txt");
	int a[3],cntw,cntr=0;
	while(!in.eof())
	{
		in>>cntw;
		cntr++;
	}
	in.close();
	in.open("main.txt");
	int jj1=0;
	while(pow(4,jj1)<=cntr/3)
	{
		jj1++;
	}
	int n1,n2;
	in.close();
	in.open("main.txt");
	int cas=0,casn=0;
	while(!in.eof())
	{
		if(cas==1)
		break;
		for(int j=0;j<4;j++)
		{
			if(cas==1)
			break;
			if(!in.eof())
			{
				in>>a[0];
				in>>a[1];
				in>>a[2];
				casn+=3;
				if(casn>cntr)
				{
					cas=1;
					break;;
				}
				sort(a,a+3);
				out[j]<<a[0]<<" ";
				out[j]<<a[1]<<" ";
				out[j]<<a[2]<<" ";
				out[j]<<endl;
			}
		}
	}
	int cnt=1,cnt1=0,cnt2=0,cnt3=0;
	while(cnt2<jj1-1)
	{
		cnt2++;
		if(cnt%2!=0)
		{
			ifstream inn[4];
			ofstream outt[4];
			inn[0].open("f0.txt");
			inn[1].open("f1.txt");
			inn[2].open("f2.txt");
			inn[3].open("f3.txt");
			outt[0].open("f4.txt");
			outt[1].open("f5.txt");
			outt[2].open("f6.txt");
			outt[3].open("f7.txt");
			int e2=0;
			cnt1=0;
			while(cnt1<pow(4,jj1-cnt2-1))
			{
				cnt1++;
				int w1=pow(4,cnt);
				int arr[3*w1];
				int e1=0;
				for(int j=0;j<4;j++)
				{
					for(int j2=0;j2<3*pow(4,cnt-1);j2++)
					{
						if(!inn[j].eof())
						inn[j]>>arr[e1++];
					}
				}
				sort(arr,arr+3*w1);
				for(int j1=0;j1<3*pow(4,cnt);j1++)
				{
						outt[e2]<<arr[j1]<<" ";
				}
				outt[e2]<<endl;	
				e2=(e2+1)%4;
			}
			for(int j=0;j<4;j++)
			{
				inn[j].close();
				outt[j].close();
			}
			cnt++;
		}
		else
		{
			ifstream inn[4];
			ofstream outt[4];
			inn[0].open("f4.txt");
			inn[1].open("f5.txt");
			inn[2].open("f6.txt");
			inn[3].open("f7.txt");
			outt[0].open("f0.txt");
			outt[1].open("f1.txt");
			outt[2].open("f2.txt");
			outt[3].open("f3.txt");
			int e2=0;
			cnt3=0;
			while(cnt3<pow(4,jj1-cnt2-1))
			{
				cnt3++;
				int w1=pow(4,cnt);
				int arr[3*w1];
				int e1=0;
				for(int j=0;j<4;j++)
				{
					for(int j2=0;j2<3*pow(4,cnt-1);j2++)
					{
						if(!inn[j].eof())
						inn[j]>>arr[e1++];
					}
				}
				sort(arr,arr+3*w1);
				for(int j1=0;j1<3*pow(4,cnt);j1++)
				{
						outt[e2]<<arr[j1]<<" ";
				}
				outt[e2]<<endl;	
				e2=(e2+1)%4;
			}
			for(int j=0;j<4;j++)
			{
				inn[j].close();
				outt[j].close();
			}
			cnt++;
		}
	}
	ofstream outf;
	outf.open("ff.txt");
	if(cnt%2==1)
	{
		ifstream inf;
		inf.open("f0.txt");
		int taking,takingcnt=0;
		while(takingcnt<cntr)
		{
			takingcnt++;
			inf>>taking;
			if(taking!=1000)
			outf<<taking<<" ";
		}
	}
	else
	{
		ifstream inf;
		inf.open("f4.txt");
		int taking,takingcnt=0;
		while(takingcnt<cntr)
		{
			takingcnt++;
			inf>>taking;
			if(taking!=1000)
			outf<<taking<<" ";
		}
	} 
}
