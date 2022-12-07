#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(2)
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
int a[N],b[N];
int l[N],r[N];
unordered_map<int,bool>is[N];
unordered_map<int,bool>now[2];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    std::cout.tie(0);
    int t;
    cin>>t;
    int cur=1;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            l[i]=r[i]=i;
        }
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)cin>>b[i];
        for(int i=1;i<=n;i++){
            is[i].clear();
            int tmp=a[i];
            for(int j=2;j*j<=tmp;j++){
                while(tmp%j==0){
                    is[i][j]=1;
                    tmp/=j;
                }
            }
            if(tmp>1)is[i][tmp]=1;
            // for(auto x:is[i]){
            //     cout<<i<<' '<<"he : ";
            //     cout<<x.first<<' '<<x.second<<'\n';
            // }
        }
        now[0].clear();
        now[1].clear();
        for(int i=1;i<=n;i++){
            int pre=cur^1;
            if(is[i][b[i-1]]&&r[i-1]>=i){
                l[i]=l[i-1];
                r[i]=r[i-1];
                continue;
            }else if(is[i][b[i-1]]){
                l[i]=l[i-1];
                r[i]=i;
                int lf=l[i];
                int rt=r[i];
                for(auto x:is[i]){
                    if(x.second==0)continue;
                    now[cur][x.first]=1;
                }
                while(now[cur][b[lf-1]]||now[cur][b[rt]]){
                    if(now[cur][b[lf-1]]){
                        lf--;
                        for(auto x:is[lf]){
                            if(x.second==0)continue;
                            now[cur][x.first]=1;
                        }
                    }else{
                        rt++;
                        for(auto x:is[rt]){
                            if(x.second==0)continue;
                            now[cur][x.first]=1;
                        }
                    }
                }
                l[i]=lf;
                r[i]=rt;
                continue;
            }
            int pos=i;
            bool flag=0;
            for(int j=i;j<=n;j++){
                for(auto x:is[j]){
                    if(x.second==0)continue;
                    now[pre][x.first]=1;
                }
                if(now[pre][b[i-1]]){
                    flag=1;
                    l[i]=l[i-1];
                    r[i]=r[i-1];
                    break;
                }
                if(now[pre][b[j]]){
                    pos=j+1;
                }else{
                    break;
                }
            }
            if(!flag){
                cur=pre;
            }
            l[i]=i;
            r[i]=pos;
        }
        while(m--){
            int x,y;
            cin>>x>>y;
            if(y>=l[x]&&y<=r[x])std::cout<<"Yes\n";
            else std::cout<<"No\n";
        }
    }
    // std::cout.flush();
    // std::system("pause");
    return 0;
}