#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#define MAX 100
using namespace std;
struct student
{
    char rno[3];
   // char name[16];
    char subject[3];
};
int main()
{

  ofstream out;
/*out.open("sno.txt");
    for(int i=0;i<4*MAX;i++)
  {
      out<<".";
  }
  out.close();
  out.open("sub.txt");
  for(int i=0;i<4*MAX;i++)
  {
      out<<".";
  }
  out.close();
  out.open("key.txt");
  for(int i=0;i<12*MAX;i++)
  {
      out<<".";
  }
  out.close();*/
  out.open("sno.txt",ios::trunc);
  out.close();
  out.open("sub.txt",ios::trunc);
  out.close();
  out.open("key.txt",ios::trunc);
  out.close();
  int n;
  cin>>n;
  student s[n];
  ifstream in1[2*n];
  cout<<"enter student info"<<endl;
  for(int i=0;i<n;i++)
  {
      cout<<"enter student roll no"<<endl;
      cin>>s[i].rno;
      cout<<"enter subject code"<<endl;
      cin>>s[i].subject;
  }
  int no_of_elements_in_file=0;
  for(int i=0;i<n;i++)
  {
      string main_input;
      main_input="";
      main_input=main_input+s[i].rno;
      if(strlen(s[i].rno)==1){main_input=main_input+" ";}
      main_input=main_input+s[i].subject;
      if(strlen(s[i].subject)==1){main_input=main_input+" ";}
      char no[3];
      no[2]='\0';
      no[1]=(no_of_elements_in_file%10)+'0';
      if(no_of_elements_in_file>=10)
      {
          no[0]=((no_of_elements_in_file/10))+'0';
      }
      else
      {
          no[0]=' ';
      }
      cout<<"no="<<no<<endl;
      in1[i].open("sno.txt");
      int off1=0,f=0;
      char ch,check[3];
      cout<<"end="<<in1[i].eof()<<endl;
      while(!in1[i].eof())
      {
          in1[i].seekg(+4*off1,ios::beg);
          if(in1[i].eof())
          {
              break;
          }
          in1[i].get(ch);
          check[0]=ch;
          in1[i].get(ch);
          if(ch!=' ')
          {
           check[1]=ch;
           check[2]='\0';
          }
          else
          {
              check[1]='\0';
          }
          if(strcmp(s[i].rno,check)==0)
          {
              f=1;
              in1[i].get(ch);
              check[0]=ch;
              in1[i].get(ch);
              check[1]=ch;check[2]='\0';
              break;
          }
          off1++;
      }
      if(!f)
      {
          in1[i].close();
          out.open("sno.txt",ios::app);
          string input;
          input=input+s[i].rno;
          if(strlen(s[i].rno)==1)
          {
              input=input+" ";
          }
          input=input+no;
          out<<input;
          out.close();
          main_input=main_input+"****";
      }
      else
      {
         // cout<<"check="<<atoi(check)<<endl;
          in1[i].close();
          in1[i].open("key.txt");
          in1[i].seekg(+(12*atoi(check)+4),ios::beg);
          char fwptr[3];
          in1[i].get(ch);
          fwptr[0]=ch;
          in1[i].get(ch);
          fwptr[1]=ch;
          fwptr[2]='\0';
          char sto[3];
          sto[0]=check[0];
          sto[1]=check[1];
          //if(sto[1]!='\0')
          sto[2]='\0';
          char star[3]={'*','*','\0'};
          while(strcmp(fwptr,star)!=0)
          {
              cout<<"s="<<i;
              sto[0]=fwptr[0];sto[1]=fwptr[1];sto[2]='\0';
              in1[i].seekg(+(12*atoi(sto)+4),ios::beg);
              in1[i].get(ch);
              fwptr[0]=ch;
              in1[i].get(ch);
              fwptr[1]=ch;
              fwptr[2]='\0';
          }
          int k=atoi(sto),l=1;
          string first;
          in1[i].close();
          in1[i].open("key.txt");
          while(l<=(12*k+4))
          {
              in1[i].get(ch);
              cout<<ch;
              first=first+ch;
              l++;
          }
          cout<<endl;
          first=first+no;
          //in1[i].get(ch);
         // cout<<"ch="<<ch<<endl;
          //in1[i].get(ch);
          //cout<<"ch="<<ch<<endl;
         // if(no_of_elements_in_file==1)
         // in1[i].seekg(+(12*k+7),ios::beg);
         // else
          in1[i].seekg(+2,ios::cur);
          int india=0;
          while(!in1[i].eof())
          {
              in1[i].get(ch);
              cout<<++india<<ch<<endl;
              if(!in1[i].eof())
              first=first+ch;
          }
          ///cout<<"first="<<first<<endl;
          in1[i].close();
          out.open("key.txt");
          out<<first;
          out.close();
          cout<<"sto="<<sto<<endl;
          main_input=main_input+"**"+sto;
      }
      in1[i+n].open("sub.txt");
      int off2=0,f1=0;
      char ch1,check1[3];
      while(!in1[i+n].eof())
      {
          in1[i+n].seekg(+4*off2,ios::beg);
          if(in1[i+n].eof())
          {
              break;
          }
          in1[i+n].get(ch1);
          check1[0]=ch1;
          in1[i+n].get(ch1);
          if(ch1!=' ')
          {
           check1[1]=ch1;
          check1[2]='\0';
          }
          else
          {
              check1[1]='\0';
          }
          if(strcmp(s[i].subject,check1)==0)
          {
              f1=1;
              in1[i+n].get(ch1);
              check1[0]=ch1;
              in1[i+n].get(ch1);
                check1[1]=ch1;check1[2]='\0';
              break;
          }
          off2++;
      }
      if(!f1)
      {
          in1[i+n].close();
          out.open("sub.txt",ios::app);
          string input1;
          input1=input1+s[i].subject;
          if(strlen(s[i].subject)==1)
          {
              input1=input1+" ";
          }
          input1=input1+no;
          out<<input1;
          out.close();
          main_input=main_input+"****";
      }
      else
      {
          in1[i+n].close();
          in1[i+n].open("key.txt");
          in1[i+n].seekg(+(12*atoi(check1)+8),ios::beg);
          char fwptr1[3];
          in1[i+n].get(ch1);
          fwptr1[0]=ch1;
          in1[i+n].get(ch1);
          fwptr1[1]=ch1;
          fwptr1[2]='\0';
          char sto1[3];
          sto1[0]=check1[0];
          sto1[1]=check1[1];
          if(sto1[1]!='\0')
          sto1[2]='\0';
          char star1[3]={'*','*','\0'};
          while(strcmp(fwptr1,star1)!=0)
          {
              cout<<"r="<<i;
              sto1[0]=fwptr1[0];sto1[1]=fwptr1[1];sto1[2]='\0';
              in1[i+n].seekg(+(12*atoi(fwptr1)+8),ios::beg);
              in1[i+n].get(ch1);
              fwptr1[0]=ch1;
              in1[i+n].get(ch1);
              fwptr1[1]=ch1;
              fwptr1[2]='\0';
          }
          int k=atoi(sto1),l1=0;
          string first1;
          in1[i+n].close();
          in1[i+n].open("key.txt");
          while(l1<12*k+8)
          {
              in1[i+n].get(ch1);
              first1=first1+ch1;
              l1++;
          }
          first1=first1+no;
          //if(no_of_elements_in_file==1)
          //in1[i+n].seekg(+(12*k+11),ios::beg);
          //else
          in1[i+n].seekg(+2,ios::cur);
          while(!in1[i+n].eof())
          {
              in1[i+n].get(ch1);
              if(!in1[i+n].eof())
              first1=first1+ch1;
          }
          in1[i+n].close();
          out.open("key.txt");
          out<<first1;
          out.close();
          cout<<"sto1="<<sto1<<endl;
          main_input=main_input+"**"+sto1;
      }
      out.open("key.txt",ios::app);
      out<<main_input;
      out.close();
      no_of_elements_in_file++;
  }
  string c1,c2,tester;
  cout<<"enter the course codes"<<endl;
  cin>>c1>>c2;
  ifstream in;
  int offset=0;
  in.open("sub.txt");
  char ch;
  char fptr[3];
  while(!in.eof())
  {
      tester="";
      in.seekg(+4*offset,ios::beg);
      in.get(ch);
      if(ch!=' ')
      tester=tester+ch;
      in.get(ch);
      if(ch!=' ')
      tester=tester+ch;
      if(tester==c1)
      {
          in.get(ch);
          fptr[0]=ch;
          in.get(ch);
          fptr[1]=ch;
          fptr[2]='\0';
          break;
      }
      offset++;
  }
  in.close();
  ifstream fin;
  string stud[50];
  fin.open("key.txt");
  fin.seekg(+12*atoi(fptr),ios::beg);
  int ind=0;
  fin.get(ch);
  stud[0]=stud[0]+ch;
  fin.get(ch);
  stud[0]=stud[0]+ch;
  fin.seekg(+6,ios::cur);
  fin.get(ch);
  fptr[0]=ch;
  fin.get(ch);
  fptr[1]=ch;
  fptr[2]='\0';
  ind=1;
  char star3[3]={'*','*','\0'};
  while(strcmp(star3,fptr))
  {
      string medium;
      fin.seekg(+12*atoi(fptr),ios::beg);
      fin.get(ch);
      medium=medium+ch;
      fin.get(ch);
      medium=medium+ch;
      stud[ind]=medium;
      ind++;
      fin.seekg(+6,ios::cur);
      fin.get(ch);
      fptr[0]=ch;
      fin.get(ch);
      fptr[1]=ch;
      fptr[2]='\0';
  }
  fin.close();
  for(int j=0;j<ind;j++)
  {
      ifstream in2;
      in2.open("sno.txt");
      int off=0;char f[3];
      while(!in2.eof())
      {
           string t;
           in.seekg(+4*off,ios::beg);
           in2.get(ch);
           t=t+ch;
           in2.get(ch);
           t=t+ch;
           if(t==stud[j])
           {
               in2.get(ch);
               f[0]=ch;
               in2.get(ch);
               f[1]=ch;
               f[2]='\0';
               break;
           }
      }
      in2.close();
      in2.open("key.txt");
      //in2.seekg(+12*atoi(f)+,ios::beg);
      char star[3]={'*','*','\0'};
      while(strcmp(f,star))
      {
          string tester2;
          in2.seekg(+(12*atoi(f)+2),ios::beg);
          in2.get(ch);
          if(ch!=' ')
          tester2=tester2+ch;
          in2.get(ch);
          if(ch!=' ')
          tester2=tester2+ch;
          if(tester2==c2)
          {
              cout<<stud[j]<<endl;
              break;
          }
          else
          {
              in2.get(ch);
              f[0]=ch;
              in2.get(ch);
              f[1]=ch;
              f[2]='\0';
          }
      }
  }
  return 0;
}
