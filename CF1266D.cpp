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
vector<pair<int,ll> >mp[N];
ll ind[N]={};
ll od[N]={};
vector<pair<int,ll> >ans[N];
vector<pair<int,ll> >sous;
vector<pair<int,ll> >to;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        ind[y]+=z;
        od[x]+=z;
    }
    for(int i=1;i<=n;i++){
        ll mi=min(ind[i],od[i]);
        ind[i]-=mi,od[i]-=mi;
        if(ind[i]){
            to.push_back(make_pair(i,ind[i]));
        }else if(od[i]){
            sous.push_back(make_pair(i,od[i]));
        }
    }
    int pos=0;
    int anss=0;
    for(auto pr:sous){
        int now=pr.first;
        ll re=pr.second;
        while(re){
            if(to[pos].second==0)pos++;
            ll tmp=min(to[pos].second,re);
            re-=tmp;
            to[pos].second-=tmp;
            anss++;
            ans[now].push_back(make_pair(to[pos].first,tmp));
        }
    }
    cout<<anss<<'\n';
    for(int i=1;i<=n;i++){
        for(auto pr:ans[i]){
            cout<<i<<' '<<pr.first<<' '<<pr.second<<'\n';
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}