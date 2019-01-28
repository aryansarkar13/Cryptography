#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
string binary(int n)
{
	int r,i=0;
	stringstream s;
	while(n>0)
	{
	 r=n%2;
     s<<r;
	 n=n/2;
	 i++;
	}
	string str;
	s>>str;
	return str;
}
int snm(int a,int n,string s)
{
	int x=1;
	for(int j=(s.length()-1);j>=0;j--)
	{
			x=(x*x)%n;
	 if(s[j]=='1')
	 {
	 	x=(x*a)%n;
     }
    } 
    return x;
}
int generator(int a,int n)
{
	for(int i=1;i<=n-1;i++)
	{
	string str=binary(i);
    if(i<n-1 && snm(a,n,str)==1)
    {
    	return 0;
	}
	if(i==(n-1) && snm(a,n,str)==1)
	{
		return 1;
	}
}
}
int main() {
	int n;
	cout<<"Enter N to generate primitive element of the field. \n";
	cin>>n;
	int a[n];
	for(int i=2;i<n;i++)
	{
		a[i]=i;
	}
	for(int i=2; i<n; i++) {
		if(a[i]=='\0')
		{
			continue;
		}
		else
		for(int j=i*2;j<n;j+=i)
		{
			a[j]='\0';
		}
		}
		for(int i=2;i<n;i++)
		{
		   	if(a[i]!='\0')
			{
			    if(generator(a[i],n)==1)
			   {
			   	cout<<a[i]<<"\n";
			   }
		
			}
			
		}
		return 0;
	}
