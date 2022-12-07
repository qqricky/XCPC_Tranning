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
vector<ll>v;
bool vis[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,x,r,p,k;
    cin>>n>>x>>r>>p>>k;
    string str;
    cin>>str;
    str=' '+str+' ';
    ll val=0;
    ll ans=n*x;
    for(int i=n;i>=1;i--){
        val++;
        if(str[i]=='1'){
            v.push_back(val);
            ans-=r*val;
            vis[i]=1;
        }
    }
    ll tmp=1;
    reverse(v.begin(),v.end());
    while(str[tmp]=='1')tmp++;
    for(int i=0;k>0&&i<v.size();i++){
        if(v[i]*(p+r)>=p*(n-tmp+1)||tmp>n){
            ans+=v[i]*(p+r);
        }
        else{
            i--;
            ans+=p*(n-tmp+1);
            tmp++;
            while(vis[tmp])tmp++;
        }
        k--;
    }
    while(tmp<=n&&k>0){
        k--;
        ans+=p*(n-tmp+1);
        tmp++;
        while(vis[tmp])tmp++;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}