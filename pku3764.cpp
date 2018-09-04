#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e6+100;
int n,u,v,w;
int ch[maxn][2],tot=1;
int head[maxn],cnt;
int x[maxn];
struct edge{
	int v,w,next;
}e[maxn];
void add(int u,int v,int w)
{
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].v=v;
	e[cnt].w=w;
}
void insert(int t)
{
	static int u,c;
	u=1;
	for(int i=1<<30;i;i>>=1)
	{
		c=(t&i)?1:0;
		if(!ch[u][c])
		{
			ch[u][c]=++tot;
		}
		u=ch[u][c];
	}
	return;
}
void dfs(int i)
{
	for(int j=head[i];j;j=e[j].next)
		if(e[j].v!=i)
		{
			x[e[j].v]=x[i]^e[j].w;
			insert(x[e[j].v]);
			dfs(e[j].v);
		}
}
int find(const int  & t)
{
	static int u,c;
	u=1;
	int ans=0;
	for(int i=1<<30;i;i>>=1)
	{
		c=(i&t)?0:1;
		if(!ch[u][c])
			c=!c;
		else ans+=i;
		u=ch[u][c];
	}
	return ans;
}
int ans;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		ans=max(ans,w);
	}
	dfs(1);
#ifdef DEBUG
	cout<<"dfs is ok\n";
#endif
	for(int i=2;i<=n;i++)
		ans=max(ans,max(x[i],find(x[i])));
	cout<<ans;
	return 0;
}
