#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int cnt1[N]={};
int cnt2[N]={};
const ll mod=998244353;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    string str;
    cin>>n;
    cin>>str;
    str=' '+str;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cnt1[i]=cnt1[i-1];
        if(str[i]=='o')cnt1[i]++;
    }
    for(int i=n;i>=1;i--){
        cnt2[i]=cnt2[i+1];
        if(str[i]=='u')cnt2[i]++;
        else if(str[i]=='s'){
            ans=(ans+1ll*cnt1[i]*cnt2[i])%mod;
        }
    }
    cout<<ans;
    //cout.flush();
    //system("pause");
    return 0;
}