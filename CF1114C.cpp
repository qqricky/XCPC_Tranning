#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    ll n,b;
    cin>>n>>b;
    int cnt=0;
    map<ll,int>mp;
    ll bb=b;
    for(ll i=2;i*i<=bb;i++){
        while(bb%i==0){
            mp[i]++;
            bb/=i;
        }
    }
    if(bb>1)mp[bb]++;
    ll ans=LONG_LONG_MAX;
    for(auto it=mp.begin();it!=mp.end();it++){
        bb=it->first;
        b=it->first;
        ll cnt=0;
        while(bb<=n){
            cnt+=n/bb;
            if(bb>1e9&&b>1e9||log10(bb)+log10(b)>18){
                break;
            }
            bb*=b;
            //cout<<bb<<endl;
        }
        ans=min(ans,cnt/(it->second));
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}