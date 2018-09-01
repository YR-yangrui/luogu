#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=5e5;
int n,m;
int u,tot=1;
int ch[maxn][26];
string t;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		u=1;
		for(int j=0;j<t.size();j++)
		{
			if(!ch[u][t[j]])ch[u][t[j]]=++tot;
			if(j<t.size()-1)
				u=ch[u][t[j]];
		}
		ch[u][t[t.size()-1]]=2;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		u=1;
		for(int j=0;j<t.size();j++)
		{
			if(!ch[u][t[j]])
			{
				cout<<"WRONG\n";
				break;
			}
			if(j==t.size()-1)
				if(ch[u][t[t.size()-1]]==2)
				{
					ch[u][t[t.size()-1]]++;
					cout<<"OK\n";
				}
				else cout<<"REPEAT\n";
			u=ch[u][t[j]];
		}
	}
}
