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
vector<ll>v[N];
unordered_map<ll,ll>num;
ll cnt[N];
vector<pair<ll,ll> >st[N];
bool vis[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(cnt,0,sizeof(ll)*(n+1));
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<=n;i++)st[i].clear();
        memset(vis,0,sizeof(bool)*(n+1));
        num.clear();
        for(int i=1;i<=n;i++){
            int tp;
            cin>>tp;
            if(tp==1){
                int k;
                cin>>k;
                for(int j=1;j<=k;j++){
                    int x;
                    cin>>x;
                    v[i].push_back(x);
                }
                vis[i]=1;
            }
            else{
                int x,y;
                cin>>x>>y;
                st[i].push_back(make_pair(x,y));
            }
        }
        cnt[n]=1;
        for(int i=n;i>=1;i--){
            if(!vis[i]){
                cnt[st[i][0].first]+=cnt[i];
                cnt[st[i][0].second]+=cnt[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){
                for(ll j:v[i]){
                    num[j]+=cnt[i];
                }
            }
        }
        ll sum=0;
        ll ma=0;
        for(auto it:num){
            sum+=it.second;
            ma=max(ma,it.second);
        }
        ll s=sum/2;
        if(ma<=s){
            cout<<sum<<'\n';
        }
        else{
            cout<<2*(sum-ma)<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}