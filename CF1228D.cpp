#include <bits/stdc++.h>
#define ull unsigned long long
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
vector<int>mp[N];
map<ull,vector<int> >v;
const ull base=1333331;
int num[N];
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
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        srot(mp[i].begin(),mp[i].end());
        ull ha=0;
        for(int u:mp[i]){
            ha=ha*base+u;
        }
        v[ha].push_back(i);
    }
    if(v.size()!=3){
        cout<<-1;
        return 0;
    }
    int cnt=0;
    for(auto pr:v){
        cnt++;
        for(auto u:pr.second){
            num[u]=cnt;
        }
    }
    for(int i=1;i<=n;i++)cout<<cnt[i]<<' ';
    cout.flush();
    system("pause");
    return 0;
}