#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=105;
int n;
int a[maxn],b[maxn];
int h[maxn];
int ans=-1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(h[j]<h[i] and a[i]<a[j]+1)
				a[i]=a[j]+1;
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			if(h[j]<h[i] and b[j]+1>b[i])
				b[i]=b[j]+1;
#ifdef find
	cout<<"a : ";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	cout<<"b : ";
	for(int i=1;i<=n;i++)
		cout<<b[i]<<' ';
	cout<<endl;
#endif
	for(int i=1;i<=n;i++)
		ans=max(ans,a[i]+b[i]+1);
	cout<<n-ans;
	return 0;
}

