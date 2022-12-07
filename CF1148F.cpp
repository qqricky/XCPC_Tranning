#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll val[N],s[N];
vector<int>mp[N];
vector<int>to[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>val[i]>>s[i];
        sum+=val[i];
        int mx=0;
        for(int j=0;j<=62;j++){
            if((s[i]>>j)&1){
                mx=j;
                to[j].push_back(i);
            }
        }
        mp[mx].push_back(i);
    }
    sum/=std::abs(sum);
    ll ans=0;
    for(int i=0;i<=62;i++){
        ll tmp=0;
        for(int id:mp[i]){
            tmp+=val[id];
        }
        if(tmp*sum>0){
            ans+=(1ll<<i);
            for(int x:to[i]){
                val[x]*=-1;
            }
        }
    }
    sum=0;
    cout<<ans;
    cout.flush();
    // system("pause");
    return 0;
}