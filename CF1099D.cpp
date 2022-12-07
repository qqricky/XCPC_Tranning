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
vector<int>mp[N];
int f[N];
ll s[N];
ll sum=0;
bool flag=1;
void dfs(int now){
    ll mi=1e18;
    for(int v : mp[now]){
        dfs(v);
        if(s[v]!=-1&&s[now]>s[v]){
            flag=0;
            return;
        }
        if(s[v]==-1)continue;
        mi=min(mi,s[v]);
    }
    if(s[now]!=-1)
        mi=min(mi,s[now]);
    for(int v : mp[now]){
        if(s[v]==-1)continue;
        sum+=s[v]-mi;
    }
    //cout<<now<<' '<<s[now]<<endl;
    if(mi!=1e18)s[now]=mi;
    //cout<<now<<' '<<s[now]<<endl;
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
    for(int i=2;i<=n;i++){
        cin>>f[i];
        mp[f[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)cin>>s[i];
    dfs(1);
    if(flag){
        cout<<sum+s[1];
    }
    else{
        cout<<-1;
    }
    cout.flush();
    //system("pause");
    return 0;
}