#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const ll mod=1e9+7;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll fac[N];
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=fac[i-1]*i%mod;
    }
}
ll c(ll n,ll m){
    return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2)%mod;
}
ll a(ll n,ll m){
    if(n<m||n==0)return 0;
    return fac[n]*powq(fac[n-m],mod-2)%mod;
}
int cnt[8];
unordered_map<string,int>num;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    int id=0;
    while(t--){
        id++;
        string str;
        cin>>str;
        int n=str.length();
        str=' '+str;
        memset(cnt,0,sizeof(cnt));
        num.clear();
        set<string>st;
        for(int i=1;i<=n;i+=2){
            string c=str.substr(i,2);
            num[c]++;
            st.insert(c);
            // cout<<c<<' '<<num[c]<<endl;
        }
        for(auto c:st){
            cnt[num[c]]++;
        }
        int dui=cnt[2]+cnt[3]+cnt[4];
        int tp=cnt[1]+cnt[2]+cnt[3]+cnt[4];
        ll s=7-dui;
        ll ans=0;
        ll x=cnt[1];
        ll y=7-dui-x;
        // cout<<dui<<' '<<s<<' '<<tp<<endl;
        if(tp>=7){
            // ll val=fac[123]%mod;
            // val=(val*powq())
            for(int i=7-dui;i<=123;i++){
                ll k=i;
                // ll p=c(x,s)*c(s,1)%mod*a(i,s-1)%mod*a(123-3-(s-1),k-s)%mod;
                // p=p*powq(123,k)%mod;
                ll p=c(tp-dui,7-dui)*c(s,1)%mod*a(k-1,s-1)%mod*a(123-3-(s-1)-3*(x-s),k-s)%mod;
                p=(p*powq(3,s))%mod;
                p=(p*powq(a(123,k),mod-2))%mod;
                ans=(ans+(p*i)%mod)%mod;
            }
        }else{
            // for(int i=7-dui;i<=123;i++){
            //     ll k=i;
            //     ll p=c(34-dui-x,y)%mod;
            //     ll val1=c(x,1)%mod*powq(c(4,2),y)%mod*a(k-1,2*y+x-1)%mod*a(123-4*y-3*x,k-2*y-x)%mod;
            //     ll val2=c(y,1)*powq(6,y)%mod*a(k-1,2*y-1+x)%mod*a(123-4*y-3*x,k-2*y-x)%mod;
            //     p=(p*((val1+val2)%mod))%mod;
            //     ans=(ans+(p*i)%mod)%mod;
            // }
        }
        cout<<"Case #"<<id<<": "<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}