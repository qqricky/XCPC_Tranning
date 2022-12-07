#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
vector<pair<int,double> >mp[N];
double w=1;
double eps=1e-8;
int st;
bool can=0;
double acu[N];
int n,m;
bool vis[N];
priority_queue<pair<double,int> >q;
void dfss(int now,double val,int len){
    if((len>m)){
        // cout<<w<<"    :\n";
        // cout<<now<<' '<<fixed<<setprecision(6)<<val<<endl;
        can=1;
        return;
    }
    if(acu[now]>val)return;
    acu[now]=val;
    for(auto pr:mp[now]){
        dfss(pr.first,val*pr.second*w,len+1);
    }
}
int pre[N];
int deep[N];
long double val[N];
void dfs(int u,int fa,int de,long double va){
    pre[u]=fa;
    deep[u]=de;
    val[u]=va;
    for(auto pr:mp[u]){
        int it=pr.first;
        // if(it==fa)continue;
        if(deep[it]){
            if(deep[u]>deep[it]){
                int sz=deep[u]-deep[it]+1;
                int pos=u;
                long double tmp=val[u]-val[it]+log(pr.second)+log(w);
                // cout<<u<<' '<<it<<' '<<sz<<endl;
                if(tmp>0){
                    can=1;
                    return;
                }
            }
        }
        else{
            dfs(it,u,de+1,va+log(pr.second)+log(w));
        }
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    srand(time(0));
    for(int i=1;i<=n;i++){
        mp[i].clear();
    }
    for(int i=1;i<=m;i++){
        int a,x,y,b;
        cin>>a>>x>>b>>y;
        mp[x].push_back(make_pair(y,1.0*b/(double)a));
    }
    long double r=1.0;
    long double l=0.00000;
    while(fabs(r-l)>=eps){
        long double mid=(l+r)*0.5;
        w=mid;
        can=0;
        for(int i=1;i<=n;i++){
            memset(deep,0,sizeof(int)*(n+5));
            memset(val,0,sizeof(double)*(n+5));
            memset(pre,0,sizeof(int)*(n+5));
            // if(deep[i])continue;
            if(can)break;
            dfs(i,0,0,0);
        }
        /*
        for(int i=1;i<=n;i++){
            while(q.size())q.pop();
            int x=i;
            st=x;
            for(int i=1;i<=n;i++){
                acu[i]=-114514.0;
            }
            memset(vis,0,sizeof(bool)*(n+3));
            acu[st]=0.0;
            vis[st]=1;
            for(auto pr:mp[x]){
                // dfs(pr.first,pr.second,0);
                // if(can)break;
                q.push(make_pair(log(pr.second)+log(w),pr.first));
            }
            while(!q.empty()){
                auto pr=q.top();
                q.pop();
                if(!vis[pr.second]){
                    vis[pr.second]=1;
                    acu[pr.second]=pr.first;
                    for(auto p:mp[pr.second]){
                        q.push(make_pair(pr.first+log(w)+log(p.second),p.first));
                        if(vis[p.first]){
                            if(acu[p.first]<pr.first+log(w)+log(p.second)){
                                can=1;
                                break;
                            }
                        }
                    }
                }
            }
            if(can)break;
        }
        */
        if(can)r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(6)<<(l+r)*0.5<<'\n';
    // cout.flush();
    // system("pause");
    return 0;
}