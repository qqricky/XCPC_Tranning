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
int f[N];
int getfa(int x){
    return x==f[x] ? x : f[x]=getfa(f[x]);
}
void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    if(x<y){
        f[x]=y;
    }
    else if(x>y){
        f[y]=x;
    }
}
int ne[N];
int n,m;
void init(){
    for(int i=1;i<=n;i++){
        f[i]=i;
        ne[i]=i;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int u,v;
    int ans=0;
    init();
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        if(u>v)swap(u,v);
        merge(u,v);
        ne[u]=max(ne[u],v);
    }
    int val=1;
    for(int i=1;i<=n;i++){
        val=max(val,ne[i]);
        for(int j=i+1;j<=val;j++){
            int xx=getfa(i),yy=getfa(j);
            if(xx!=yy){
                merge(xx,yy);
                ans++;
            }
            val=max(val,ne[j]);
        }
        i=val;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}