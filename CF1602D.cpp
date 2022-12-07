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
int f[N];
int a[N];
int b[N];
bool vis[N]={};
int pre[N];
int n;
void print(int x){
    if(x==n){
        return;
    }
    print(pre[x]);
    cout<<x<<' ';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    memset(f,0x3f,sizeof(f));
    queue<int>q;
    q.push(n);
    int dep=n;
    f[n]=0;
    while(!q.empty()){
        int u=q.front();
        if(u==0){
            break;
        }
        q.pop();
        int v=u;
        u+=b[u];
        for(int j=dep-1;j>=u-a[u];j--){
            if(f[u]+1<f[j]){
                pre[j]=v;
                f[j]=f[v]+1;
                q.push(j);
            }
        }
        dep=min(dep,u-a[u]);
    }
    // for(int i=0;i<=n;i++)cout<<pre[i]<<' ';
    // cout<<"adsklf"<<endl;
    if(f[0]==INF)cout<<-1;
    else {
        cout<<f[0]<<'\n';
        print(0);
    }
    cout.flush();
    //system("pause");
    return 0;
}