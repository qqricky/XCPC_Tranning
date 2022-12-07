#include<bits/stdc++.h>
typedef long long ll;
#pragma GCC optimise(3)
using namespace std;
ll ans=999999999999;
ll a,b;
ll f[1000];
ll p[100000+5],tot;
bool v[100000+5];
ll N=100005;
int cntt=0;
inline ll div1(ll n){
	ll cnt=0;
	for(int i = 0;i < tot;++i){
		if(n==1) break;
		while(n%p[i]==0) n/=p[i],++cnt;
	}
	if(n!=1) ++cnt;
	return cnt;
}
void init(){
	for(int i = 2;i <= N;++i)
		if(!v[i]){
			p[tot++] = i;
			for(int j = 2;i*j <= N;++j) v[i*j] = 1;
		}
}
void dfs(ll aa,ll bb,ll cnt,int fla)
{
	if(cnt>ans)return;
	if(aa==1||bb==1)
	{
		ans=min(ans,cnt);return;
	}
	ans=min(ans,cnt+abs(1-aa));
	int i;
	for(i=cntt;i>=1;i--)
	{
		if(aa%f[i]==0&&bb%f[i]==0)
		dfs(aa/f[i],bb/f[i],cnt+1,0);
		else
		{
			dfs(aa/f[i]+1,bb/f[i]+1,1+cnt+f[i]-aa%f[i],0);
			dfs(aa/f[i],bb/f[i],1+cnt+aa%f[i],0);
		}
	}
}
int main(void)
{
	int t;
	//scanf("%d",&t);
	init();
    t=1;
    srand(time(0));
	while(1)
	{
		cntt=0;
		ll a,b;
        a=rand()*100000000,b=rand()*10000000;
        //a=998244353,b=1e9+7;
        double x=(double)clock()/CLOCKS_PER_SEC;
		//scanf("%lld %lld",&a,&b);
		if(a==b)
		{
			//printf("%lld\n",div1(a));
            continue;
		}
		if(a>b)swap(a,b);
		ll ss=b-a;
		int i;
		for(i=0;i<tot;i++)
		{
			if(ss%p[i]==0)
			{
				while(ss%p[i]==0)ss/=p[i];
				f[++cntt]=p[i];
			}
		}
		if(ss!=1)
		{
			f[++cntt]=ss;
		}
		if(cntt==1)
		{
			//printf("%lld\n",1+a%f[1]);
            continue;
		}
		if(a==b)
		{
			//printf("lld\n",cntt);
            continue;
		}
		ans=9999999999999;
		dfs(a,b,0,0);
		//printf("%lld\n",ans);
        double y=(double)clock()/CLOCKS_PER_SEC;
        if(y-x>=0.5){
            cout<<y-x<<endl;
            cout<<a<<' '<<b<<endl;
            system("pause");
        }
	}
}