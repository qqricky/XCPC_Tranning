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
ll a[N];
ll sum[N]={};
ll suf[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        k=min(k,i);
        sum[i]+=sum[i+1];
        suf[i]=suf[i+1]-sum[i];
        a[i]-=suf[i];
        if(a[i]>0){
            ll cnt=a[i]/k+(a[i]%k>0);
            //cout<<i<<' '<<cnt<<endl;
            ans+=cnt;
            sum[i]+=cnt;
            sum[max(i-k-1,0)]-=cnt;
            suf[i]+=k*cnt;
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}