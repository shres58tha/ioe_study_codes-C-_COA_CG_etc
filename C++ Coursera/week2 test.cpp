#include<iostream>
using namespace std;
const int INFINITY=9999;
void m1();
int getvalue();
void dijkstras();
int n,source,a[100][100],i,j,adj,k;
int d[100],p[100];
int v[100]={0};
int main()
{
cout<<"enter the no. of vertices"<<endl;
cin>>n;
cout<<"enter the nodes"<<endl;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cin>>a[i][j];
}
}
cout<<"enter source node"<<endl;
cin>>source;
m1();
dijkstras();
for(i=0;i<n;i++)
{
cout<<"distance of"<<i<<"is"<<endl;
cout<<d[i]<<endl;
int pnode=p[i];
while(pnode!=source)
{
cout<<"<-"<<pnode<<" ";
pnode=p[pnode];
}
cout<<endl;
}
return 0;
}
void m1()
{
for(j=0;j<n;j++)
{
p[i]=i;
d[j]=INFINITY;
}
d[source]=0;
}
int getvalue()
{
int minvalue=INFINITY;
int minnode=0;
for(i=0;i<n;i++)
{
if(!v[i] && d[i]<minvalue)
{
minvalue=d[i];
minnode=i;
}
}
return minnode;
}
void dijkstras()
{
for(k=0;k<n;k++)
{
int nearest=getvalue();
v[nearest]=1;
for(adj=0;adj<n;adj++)
{
if(a[nearest][adj]!=0 && d[adj]>d[nearest]+a[nearest][adj])
{
d[adj]=d[nearest]+a[nearest][adj];
p[adj]=nearest;
}
}
}
}
