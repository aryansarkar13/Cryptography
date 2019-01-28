#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <sstream>
using namespace std;
int gcd(int a, int b)
{
    while(b!=0)
    {
     int tp;
     tp=a%b;
     a=b; 
     b=tp;
    }
    return a;
}
int modInv(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
}
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
int main()
{
	srand(time(NULL));
	int p=103,q=91;//28351 and 33577
	int n=p*q;
	int phi=(p-1)*(q-1);
	int e=rand()%phi;//e=29,d=165
	//int e=103;
     while(e<phi)
	{
		if(gcd(e,phi)==1)
		 break;
		else
		 e++;
	}
	cout<<"Public Key: "<<n<<":"<<e<<"\n";
	//int k=rand()%phi;
   	//int d=(1+k*phi)/e;
   	int d=modInv(e,phi);//165
	cout<<d<<"\n";
	string str,s;
	cout<<"Enter data to encrypt: \n";
	getline(cin,str);
	int len=str.length();
	int a[len],x[len];
	for(int i=0;i<len;i++)
	{
		a[i]=str[i];
		cout<<"\n"<<a[i]<<"\n";		 
    }
    int xyz[len];
	for(int i=0;i<len;i++)
	{
     xyz[i]=snm(a[i],n,binary(e));
	}
	cout<<"Encryption Succesful!\n";
	cout<<"Encrypted Data: \n";
	for(int i=0;i<len;i++)
	{
		cout<<xyz[i]<<" ";
	}
	cout<<"\n"<<"Decrypted Data:\n";
	int z[len];
		for(int i=0;i<len;i++)
	{
		z[i]=snm(xyz[i],n,binary(d));
		cout<<(char)z[i];
	}	
	return 0;	
}







