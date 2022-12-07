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
bool can=0;
const ll mod=998244353;
ll pow_Q(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
int a[N];
ll pdt[N]={};
int n,k;
void init(){
    pdt[0]=1;
    for(int i=1;i<=n;i++){
        pdt[i]=pdt[i-1]*(k-1)%mod;
    }
}
ll solve(vector<int>&v){
    // for(int x:v){
    //     cout<<x<<' ';
    // }
    // cout<<endl;
    int pre=0;
    int cnt=0;
    int st=1,ed=v.size()-1;
    while(v[st]==-1&&st<v.size()){
        st++;
    }
    while(v[ed]==-1&&ed>0){
        ed--;
    }
    if(st>ed){
        return pdt[v.size()-2]*k%mod;
    }
    int pos=st+1;
    pre=st;
    ll ans=1;
    while(pos<=ed){
        while(v[pos]==-1){
            pos++;
            cnt++;
        }
        // cout<<pre<<' '<<pos<<endl;
        // cout<<v[pre]<<' '<<v[pos]<<endl;
        if(cnt==0){
            pre=pos;
            pos++;
            continue;
        }
        if(v[pos]==v[pre]){
            int s=1;
            ll tmp=0;
            for(int j=cnt;j>1;j--,s*=-1){
                tmp=(tmp+pdt[j]*s)%mod;
                if(tmp<0){
                    tmp=(tmp%mod+mod)%mod;
                }
            }
            tmp=((tmp+(k-1)*s)%mod+mod)%mod;
            if(tmp)ans=(ans*tmp)%mod;
        }
        else{
            can=1;
            int s=1;
            ll tmp=0;
            for(int j=cnt;j>1;j--,s*=-1){
                tmp=(tmp+pdt[j]*s)%mod;
                if(tmp<0){
                    tmp=(tmp%mod+mod)%mod;
                }
            }
            tmp=((tmp+(k-2)*s)%mod+mod)%mod;
            if(tmp)ans=(ans*tmp)%mod;
        }
        pre=pos;
        pos++;
        cnt=0;
    }
    //cout<<"jlsdf "<<st-1+v.size()-ed-1<<endl;
    ans=(ans*pdt[st-1+v.size()-ed-1])%mod;
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>a1,a2;
    a1.push_back(0),a2.push_back(0);
    cin>>n>>k;
    init();
    bool flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2){
            if(a[i]==a[i-2]&&a[i]!=-1){
                flag=0;
            }
        }
        if(i&1)a1.push_back(a[i]);
        else a2.push_back(a[i]);
    }
    ll anss=solve(a1)*solve(a2)%mod;
    if(k==2&&can){
        cout<<0;
        return 0;
    }
    if(!flag){
        cout<<0;
        return 0;
    }
    cout<<anss;
    cout.flush();
    //system("pause");
    return 0;
}