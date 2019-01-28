#include <iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Eratosthenes Sieve \nEnter Number:\n";
	cin>>n;
	int a[(n-1)];
	for(int i=2;i<=n;i++)
	{
	 a[i]=i;
	}
    for(int i=2;i<n;i++)
	{
		if(a[i]!=0)
		{
	 for(int k=(2*i);k<n;k+=i)
	 {
	 	a[k]=0; 	
	 }
        }
        else
        {
        	continue;
		}
	}
	for(int j=2;j<n;j++)
	{
		if(a[j]!=0)
	cout<<a[j]<<"\t";
	else
	continue;
}
	return 0;   
}
