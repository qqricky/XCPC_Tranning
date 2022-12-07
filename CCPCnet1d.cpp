#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
vector<int>v[100];
ll get(ll d,ll g)
{
	int x = lower_bound(v[g].begin(),v[g].end(),d)-v[g].begin();
	if(v[g][x]>n){
        x=lower_bound(v[g].begin(),v[g].end(),d)-v[g].begin()-1;
        if(x>0){
            return v[g][x];
        }
        else return n;
    }
    return v[g][x];
}
ll get2(ll d,ll g)
{
    int x=lower_bound(v[g].begin(),v[g].end(),d)-v[g].begin()-1;
    if(x<0)return 1;
    return v[g][x];
}
ll ck(ll i)
{
	ll ans =0 ;
	while(i)
	{
		ans += i%10;
		i/=10;
	}
	return ans;
}
int main()
{
	for(int i = 1;i <= 1000000;++i)
	{
		int x = ck(i);
		v[x].push_back(i);
	}
	int T;cin >> T;
	while(T--)
	{
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
		ll ans = a+b+c+d;
		for(int g = 1;g <= 54;++g)
		{
			ll D = -(c*g*g+d*g)/(2*(a*g+b));
			ll x = get(D,g);
			ll res = a*x*x*g+b*x*x+c*x*g*g+d*x*g;
			//cout << d << ' ' << x << ' ' << res << endl;
			ans = min(res,ans);

		}
		printf("%lld\n",ans);
	}
	return 0;
}