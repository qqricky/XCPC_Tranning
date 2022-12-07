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
int mp[N][10];
int u=1,v=1;
int vis[(1<<8)];
int n,m;
bool ck(int x){
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        int tmp=0;
        for(int j=0;j<m;j++){
            if(mp[i][j+1]>=x){
                tmp|=(1<<j);
            }
        }
        vis[tmp]=i;
    }
    for(int i=0;i<=(1<<m)-1;i++){
        for(int j=0;j<=(1<<m)-1;j++){
            if((i|j)>=((1<<m)-1)){
                if(vis[i]>0&&vis[j]>0){
                    u=vis[i],v=vis[j];
                    //cout<<x<<endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int ma=0;
    int pos;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            ma=max(ma,mp[i][j]);
        }
    }
    int l=0,r=ma;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(ck(mid))l=mid;
        else r=mid-1;
    }
    cout<<u<<' '<<v;
    cout.flush();
    //system("pause");
    return 0;
}