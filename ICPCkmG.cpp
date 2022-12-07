#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll c[N];
ll v[N];
ll x[N];
ll y[N];
ll f[366][505]={};
ll fi[17];
ll n,m,w;
void dfs(ll num,ll cnt,ll re,ll tot)
{
    if(re<0)return;
    fi[cnt]=max(fi[cnt],tot);
    if(num>m)return;
    dfs(num+1,cnt+1,re-x[num],tot+y[num]);
    dfs(num+1,cnt,re,tot);
}
void dfs2(int i,int cnt,int now,int v) {
    if(v>fi[cnt])fi[cnt]=v;
    if(i==m) return;
    int ans(0);
    if(now>=x[i]) dfs(i+1,cnt+1,now-x[i],v+y[i]);
    dfs(i+1,cnt,now,v);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    for(int i=1;i<=12;i++)day[i]+=day[i-1];
    cin>>t;
    while(t--)
    {
        vector<int>fr[366];
        memset(f,0,sizeof(f));
        memset(fi,0,sizeof(fi));
        cin>>n>>m>>w;
        int tmp,a,b;
        string str;
        for(int i=1;i<=n;i++){
            cin>>str;
            int pos=0;
            while(str[pos]!='-')pos++;
            a=((str[pos+1]-'0')*10+str[pos+2]-'0');
            b=((str[str.length()-2]-'0')*10+str[str.length()-1]-'0');
            int tt=a;
            int ttt=b;
            tmp=day[a-1]+b;
            cin>>a>>b;
            if(tt==2&&ttt==29)continue;
            c[i]=a;
            v[i]=b;
            //cout<<tmp<<endl;
            fr[tmp].push_back(i);
        }
        ll ans=0;
        dfs(1,0,w,0);
        for(int i=1;i<=m;i++)fi[i]=max(fi[i-1],fi[i]);
        for(int i=1;i<=m;i++)cin>>x[i]>>y[i];
        for(int i=1;i<=365;i++){
            for(int j=0;j<fr[i].size();j++){
                int pos=fr[i][j];
                for(int k=m;k>0;k--){
                    for(int q=i;q>=c[pos];q--){
                        //f[i][q][k]=f[i-1][q][k];
                        f[q][k]=max(f[q][k],f[q-c[pos]][k]+v[pos]);
                        if(k)f[q][k]=max(f[q][k],f[q][k-1]-fi[k-1]+fi[k]);
                        ans=max(ans,f[q][k]);
                    }
                }
            }
        }
        // for(int i=n;i>=0;i--){
        //     for(int j=1;j<=365;j++){
        //         ans=max(ans,f[j][i]+fi[min(m,n-i)]);
        //     }
        // }
        //for(int i=1;i<=m;i++)cout<<fi[i]<<endl;
        //for(int i=1;i<=365;i++)cout<<i<<'Q'<<f[i][4]<<endl;
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}