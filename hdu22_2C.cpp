#pragma GCC optimise(3)
#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
int dep[N];
int col[N];
int ta[N];
int tb[N];
int tc[N];
int fa[N];
int ind[N];
bool isc[N];
int trans[N];
void getid(int now){

}
void getdep(int now){
    for(int x:mp[now]){
        dep[x]=dep[now]+1;
        getdep(x);
    }
}
int ans=0;
void dfs(int now,bool is,bool can){
    if(isc[now])is=1;
    // cout<<"!   ";
    // cout<<now<<' '<<col[now]<<endl;
    if(is&&col[now]==3){
        ans++;
        can=1;
    }
    if(col[now]!=3&&can){
        return;
    }
    for(int x:mp[now]){
        dfs(x,is,can);
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            mp[i].clear();
            ind[i]=0;
        }
        dep[1]=1;
        for(int i=1;i<n;i++){
            int x;
            cin>>x;
            ind[x]++;
            mp[x].push_back(i+1);
            fa[i+1]=x;
        }
        getdep(1);
        fa[1]=0;
        while(q--){
            int a,b,c;
            cin>>a>>b>>c;
            if(a+b+c<3||a==0||b==0||c==0){
                cout<<"0\n";
                continue;
            }
            for(int i=1;i<=a;i++){
                cin>>ta[i];
            }
            for(int i=1;i<=b;i++){
                cin>>tb[i];
            }
            for(int i=1;i<=c;i++){
                cin>>tc[i];
            }
            for(int i=1;i<=n;i++){
                col[i]=0;
                isc[i]=0;
            }
            for(int i=1;i<=c;i++){
                isc[tc[i]]=1;
            }
            for(int i=1;i<=a;i++){
                int now=ta[i];
                while(!col[now]&&now){
                    col[now]=1;
                    if(isc[now])break;
                    now=fa[now];
                }
            }
            for(int i=1;i<=b;i++){
                int now=tb[i];
                while(col[now]!=2&&col[now]!=3&&now){
                    if(col[now]==1)col[now]=3;
                    else col[now]=2;
                    if(isc[now])break;
                    now=fa[now];
                }
            }
            ans=0;
            dfs(1,0,0);
            cout<<ans<<'\n';
        }
    }
    cout.flush();
    // system("pause");
    return 0;
}