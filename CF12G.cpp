#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<cstring>
typedef long long ll;
using namespace std;
const ll mod=10000000;
string s[20];
ll shu[10000][30];
ll shu1[10000][30];
ll pos[100];
bool vis[100];
bool viss[100];
int main(void)
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		string ans;
		
		ll i;for(i=1;i<=n;i++)cin>>s[i];
		memset(pos,0,sizeof(pos));
		while(1)
		{
			vector<int>ss(30,0);
			int flag=0;
			for(i=1;i<=n;i++)
			{
				if(pos[i]==s[i].size())continue;
				ss[s[i][pos[i]]-'A']++;
				flag=1;
			}
			ll maxn=-1;ll poss=-1;
			for(i=0;i<26;i++)
			{
				if(maxn<ss[i])
				{
					maxn=ss[i];
					poss=i;
				}
			}
			if(maxn==0)break;
			char cc='A'+poss;
			ans.push_back(cc);
			for(i=1;i<=n;i++)
			{
				if(pos[i]==s[i].size())continue;
				if(s[i][pos[i]]==cc)pos[i]++;
			}
			if(flag==0)break;
		}
		cout<<ans<<endl;
	}
}