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
int a[N];
int b[N];
bool vis[N];
vector<pair<int,int> >ans;
unordered_map<int,bool>is[220];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ans.clear();
        memset(vis,0,sizeof(bool)*(n+5));
        bool flag=1;
        for(int i=1;i<=n;i++)is[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            vis[i]=1;
            int cnt=0;
            int now=0;
            if(a[i]==b[i]){
                int pos=0;
                for(int j=1;j<=n;j++){
                    if(vis[j])continue;
                    if(is[i][j])continue;
                    if(cnt==0){
                        now=j;
                    }
                    cnt++;
                }
                if(cnt&1){
                    if(cnt==1){
                        flag=0;
                        break;
                    }
                    int to=0;
                    for(int j=1;j<=n;j++){
                        if(vis[j])continue;
                        if(is[i][j])continue;
                        if(j==now)continue;
                        if(is[now][j])continue;
                        to=j;
                        break;
                    }
                    is[now][to]=1;
                    is[to][now]=1;
                    swap(a[i],a[now]);
                    ans.push_back(make_pair(i,now));
                    for(int j=1;j<=n;j++){
                        if(vis[j])continue;
                        if(is[i][j])continue;
                        if(j==now)continue;
                        if(j==to)continue;
                        swap(a[i],a[j]);
                        ans.push_back(make_pair(i,j));
                    }
                    swap(a[now],a[to]);
                    ans.push_back(make_pair(now,to));
                    swap(a[to],a[i]);
                    ans.push_back(make_pair(to,i));
                }else{
                    for(int j=1;j<=n;j++){
                        if(!vis[j]&&!is[i][j]){
                            swap(a[i],a[j]);
                            ans.push_back(make_pair(i,j));
                        }
                    }
                }
            }else{
                int pos=0;
                for(int j=1;j<=n;j++){
                    if(vis[j])continue;
                    if(is[i][j])continue;
                    if(a[j]==b[i]){
                        pos=j;
                        break;
                    }
                }
                if(!pos){
                    flag=0;
                    break;
                }
                for(int j=1;j<=n;j++){
                    if(!vis[j]&&pos!=j&&!is[i][j]){
                        swap(a[i],a[j]);
                        ans.push_back(make_pair(i,j));
                    }
                }
                swap(a[i],a[pos]);
                ans.push_back(make_pair(i,pos));
            }
        }
        if(flag){
            cout<<"YES\n";
            for(auto pr:ans){
                cout<<pr.first<<" "<<pr.second<<'\n';
            }
        }else{
            cout<<"NO\n";
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}