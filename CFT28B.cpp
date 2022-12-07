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
int f[N][18]={};
vector<int>mp[N];
int dep[N];
void dfs(int now,int fa){
    for(int x:mp[now]){
        if(x==fa)continue;
        f[x][0]=now;
        dep[x]=dep[now]+1;
        dfs(x,now);
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    dep[1]=0;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=17;i++){
        for(int j=1;j<=n;j++){
            f[j][i]=f[f[j][i-1]][i-1];
        }
    }
    while(q--){
        int pos,x;
        cin>>pos>>x;
        int num=dep[pos]-x;
        if(num<=0){
            cout<<pos<<'\n';
            continue;
        }
        for(int j=0;j<=17;j++){
            if(num&(1<<j)){
                pos=f[pos][j];
                //cout<<"---> "<<pos<<'\n';
            }
        }
        cout<<pos<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}