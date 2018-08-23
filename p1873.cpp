#include<iostream>
#include<cstdio>
#include<algorithm>
#define find
using namespace std;
const int maxn=1e6+10;
long long n,m;
long long ans=-1;
long long w[maxn];
bool ok(long long q)
{
	long long l=1,r=n,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(w[mid]<q)l=mid+1;
		else r=mid-1;
	}
	long long res=0;
#ifdef find
	cout<<"start to find from "<<l<<endl;
#endif
	for(long long i=l;i<=n;i++)
		if(w[i]>q)
		res+=w[i]-q;
#ifdef find
	cout<<"res="<<res<<endl;
#endif
	if(res>=m)return true;
	return false;
}
int main()
{
	freopen("cut3.in","r",stdin);
//	freopen("cut.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	sort(w+1,w+n+1);
	long long l=0,r=w[n],mid;
	while(l<=r)
	{
		mid=l+r>>1;
#ifdef find
		cout<<"l="<<l<<" r="<<r<<" mid="<<mid<<endl;
#endif
		if(ok(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
