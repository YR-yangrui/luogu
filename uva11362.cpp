#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn=1e5;
string t;
int T,n,u,tot=1,flag,all;
int ch[maxn][26];
int p[maxn][2];
int main()
{
	cin>>T;
	while(T--)
	{
		memset(ch,0,sizeof ch);
		u=tot=1;
		flag=all=0;
		cin>>n;
		while(n--)
		{
			cin>>t;
			u=1;
			for(int i=0;i<t.size();i++)
			{
				if(!ch[u][t[i]-'0'] and i!=t.size()-1)ch[u][t[i]-'0']=++tot;
				if(i==t.size()-1)
				{
					p[++all][0]=u;
					p[all][1]=t[i]-'0';
				}
				u=ch[u][t[i]-'0'];
			}
		}
		int i;
		for(i=1;i<=all;i++)
			if(ch[p[i][0]][p[i][1]])
			{
				cout<<"NO\n";
				break;
			}
		if(i==all+1)
			cout<<"YES\n";
	}
}
