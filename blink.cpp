#include<iostream>
using namespace std;
int n;
int get_next(int s){
	return s^(s>>1)^(s&1?1<<n-1:0);
}
int main()
{
	long long b;
	cin>>n>>b;
	int s=0;
	for(int i=n-1;i>=0;i--)
	{
		int v;
		cin>>v;
		if(v)s|=1<<i;
	}
	int s0=s,s1=s;
	for(;b>0;b--)
	{
		s0=get_next(s0);
		s1=get_next(get_next(s1));
		if(s0==s1){b--;break;}
	}
	if(b)
	{
		int k=1;
		for(s0=get_next(s0);s0!=s1;k++)
			s0=get_next(s0);
		b%=k;
	}
	for(;b>0;b--)s0=get_next(s0);
	for(int i=n-1;i>=0;i--) 
		cout<<(s0&1<<i?1:0)<<endl;
	return 0;
}
