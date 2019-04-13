#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void m_way_polyphase(const char a[100][100],int* cnt,int n,int* sop,int* pos);//,int& which_file);
int all_zero_one_one(int* cnt,int n)
{
    int i1=0,i0=0;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==0)
        {
            i0++;
        }
        else if(cnt[i]==1)
        {
            i1++;
        }
    }
    return ((i0==n-1)&&(i1==1));
}
int which_one(int* cnt,int n)
{
    int i1=0,i0=0,m;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==0)
        {
            i0++;
            m=i;
        }
        else if(cnt[i]==1)
        {
            i1++;
        }
    }
    return m;
}
int minimum_among(int* arr,int n)
{
    int mini=10000,m;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<mini)
        {
            mini=arr[i];
            m=i;
        }
    }
    return m;
}
int main()
{
    const char a[100][100]={"nf1.txt","nf2.txt","nf3.txt","nf4.txt"};//,"nf5.txt","nf6.txt","nf7.txt"};
    char ch;
    int n;
    cout<<"how many files?"<<endl;
    cin>>n;
    ofstream out;
    int cnt[n],input,w=0,sop[n],pos[n];
    for(int i=0;i<n;i++)
    {
        cnt[i]=0;
        sop[i]=0;
        pos[i]=0;
    }
    for(int i=0;i<n-1;i++)
    {
        out.open(a[i]);
        do
        {
           // cout<<"enter"<<endl;
            cin>>input;
            out<<input<<" ";cnt[i]++;
           // cout<<"continue?"<<endl;
            cin>>ch;
        }while(ch=='y');
        out.close();
        sop[i]++;
    }
    for(int i=0;i<n;i++)
    {
        cout<<"cnt="<<cnt[i]<<endl;
    }
    m_way_polyphase(a,cnt,n,sop,pos);//,w);
    return 0;
}
int all_covered(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=10000)
        {
            return 0;
        }
    }
    return 1;
}
int maxi(int* sop,int n)
{
    int m=-1;
    for(int i=0;i<n;i++)
    {
        if(sop[i]>m)
        {
            sop[i]=m;
        }
    }
    return m;
}
void m_way_polyphase(const char a[100][100],int* cnt,int n,int* sop,int* pos)
{
    cout<<"*"<<endl;
    if(all_zero_one_one(cnt,n))
    {
        return;
    }
    ifstream in[n-1];int arr[n-1],corr_ind[n-1];
    ofstream o;int ind=0,mini=10000,m,input,m1;
    for(int i=0;i<n;i++)
    {
        if(cnt[i]==0)
        {
            o.open(a[i]);
            m1=i;
        }
        else
        {
            in[ind].open(a[i]);
            in[ind].seekg(+pos[i],ios::beg);
            corr_ind[ind]=i;
            ind++;
            if(mini>cnt[i])
            {
                mini=cnt[i];m=i;
            }
        }
    }
    int carr[n];
    for(int i=0;i<n;i++)
    {
        carr[i]=sop[i];
    }
    for(int i=0;i<n-1;i++)
    {
        in[i]>>arr[i];
        carr[corr_ind[i]]--;
    }
    cout<<"m="<<m<<endl;
    cout<<"m1="<<m1<<endl;
    while(cnt[m]!=0)
    {
         while(!all_covered(arr,n-1))
        {
        int ind=minimum_among(arr,n-1);
        o<<arr[ind]<<" ";
        cout<<arr[ind]<<" ";
        if(carr[corr_ind[ind]]==0)
        {
         arr[ind]=10000;
         cnt[corr_ind[ind]]--;
        }
        else
        {
          if(!in[ind].eof())
          {
            in[ind]>>input;
          if(in[ind].eof())
          {
              arr[ind]=10000;
              carr[corr_ind[ind]]=0;
              cnt[corr_ind[ind]]--;
          }
          else
          {
              arr[ind]=input;
              carr[corr_ind[ind]]--;
          }
          }
          else
          {
              arr[ind]=10000;
              carr[corr_ind[ind]]=0;
              cnt[corr_ind[ind]]--;
          }
        }
        }
        cnt[m1]++;
    if(cnt[m]==0)
    {
        break;
    }
    for(int i=0;i<n;i++)
    {
        carr[i]=sop[i];
    }
    for(int i=0;i<n-1;i++)
    {
        in[i]>>arr[i];
        carr[corr_ind[i]]--;
    }
    }
    int s=0;
    for(int i=0;i<n;i++)
    {
        s=s+sop[i];
    }
    sop[m1]=s;
    sop[m]=0;
    for(int i=0;i<n-1;i++)
    {
        if(!in[i].eof())
        pos[corr_ind[i]]=in[i].tellg();
        else
        pos[corr_ind[i]]=0;
    }
    pos[m1]=0;
     for(int i=0;i<n-1;i++)
    {
        in[i].close();
    }
    o.close();
    for(int i=0;i<n;i++)
    {
        cout<<"cnt="<<cnt[i]<<endl;
    }
    m_way_polyphase(a,cnt,n,sop,pos);
    return;
}
//12 y 23 y 34 y 45 y 56 y 67 y 78 n 20 y 25 y 36 y 40 y 42 y 60 n 31 y 41 y 61 y 71 n
