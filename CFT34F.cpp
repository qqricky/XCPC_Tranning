#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>mp;
int shu[100006][10];
int pai[10000];
void fun(int *a,int cnt)
{
	int i;int cntt=0;
	for(i=1;i<=(1<<cnt)-1;i++)
	{
		int now=0;
		int j;
		for(j=0;j<=cnt-1;j++)
		{
			if(((1<<(j))&i)!=0)
			{
				now=now*10;
				now+=a[j+1];
			}
		}
		pai[++cntt]=now;
	}
	sort(pai+1,pai+1+cntt);
	for(i=1;i<cntt;i++)
	{
		if(pai[i]==pai[i+1])continue;
		mp[pai[i]]++;
	}
	if(pai[cntt]!=pai[cntt-1])mp[pai[cntt]]++;
}
void fun1(int *a,int cnt)
{
	int i;int cntt=0;
	for(i=1;i<=(1<<cnt)-1;i++)
	{
		int now=0;
		int j;
		for(j=0;j<=cnt-1;j++)
		{
			if(((1<<(j))&i)!=0)
			{
				now=now*10;
				now+=a[j+1];
			}
		}
		pai[++cntt]=now;
	}
	sort(pai+1,pai+1+cntt);
	for(i=1;i<cntt;i++)
	{
		if(pai[i]==pai[i+1])continue;
		mp[pai[i]]--;
	}
	if(pai[cntt]!=pai[cntt-1])mp[pai[cntt]]--;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n,k;
	cin>>n>>k;
	int i;
	char op;
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		cin>>op;
		if(op=='C')
		{
			;int zcnt;
			scanf("%d",&zcnt);
			int j;cnt++;
			for(j=1;j<=zcnt;j++)
			{
				scanf("%d",&shu[cnt][j]);
			}
			sort(shu[cnt]+1,shu[cnt]+1+zcnt);
			fun(shu[cnt],zcnt);
		}
		if(op=='J')
		{
			int shu;int zcnt;
			scanf("%d",&zcnt);
			int sh[10];
			int j;
			for(j=1;j<=zcnt;j++)
			{
				scanf("%d",&sh[j]);
			}
			sort(sh+1,sh+1+zcnt);
			int now=0;
			for(j=1;j<=zcnt;j++)
			{
				now=now*10;
				now+=sh[j];
			}
			printf("%d\n",mp[now]);
		}
		if(op=='D')
		{
			int zcnt;
			scanf("%d",&zcnt);
			int sh[10];
			int j;
			for(j=1;j<=9;j++)
			{
				if(shu[zcnt][j]==0)break;
				sh[j]=shu[zcnt][j];
			}
			sort(sh+1,sh+1+j-1);
			fun1(sh,j-1);
		}
	}
}