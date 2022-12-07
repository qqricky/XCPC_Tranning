#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
const ull maxx=1e18;
vector<ull>p1,p2,p;
vector<ull>a,b;
void dfs(ull val,ull last,vector<ull>&prime,vector<ull>&v){
    v.push_back(val);
    for(ull x : prime){
        if(x<last)continue;
        // __int128 tmp=x;
        // __int128 tmp2=val;
        // __int128 tmpp=tmp*tmp2;
        // if(x*val!=tmpp){
        //     cout<<x<<' '<<val<<endl;
        //     system("pause");
        // }
        if((__int128)x*val<=maxx){
            dfs(x*val,x,prime,v);
        }
    }
}
ll ck(ll up){
    ll cnt=0;
    for(ll x : a){
        ll tmp=up/x;
        ll num=upper_bound(b.begin(),b.end(),tmp)-b.begin();
        //cout<<up<<' '<<x<<' '<<num<<':'<<b[num-1]<<' '<<up/x<<endl;
        cnt+=num;
    }
    return cnt;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll val;
        cin>>val;
        p.push_back(val);
    }
    ll k;
    cin>>k;
    sort(p.begin(),p.end());
    //a.push_back(1),b.push_back(1);
    for(int i=0;i<p.size();i++){
        if(i&1){
            p1.push_back(p[i]);
        }
        else{
            p2.push_back(p[i]);
        }
    }
    dfs(1,1,p1,a);
    dfs(1,1,p2,b);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<b.size()-1;i++){
        if(b[i]==b[i+1]){
            cout<<b[i]<<endl;
        }
    }
    ll l=0,r=maxx,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(ck(mid)>=k){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<r<<endl;
    cout.flush();
    //system("pause");
    return 0;
}