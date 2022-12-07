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
ll f[110][110][2];
const ll mod=1e9+7;
vector<int>con[2][2];
string ss;
int pi[N];
int cnt[2][2];
void prefix_function(){
    int n=ss.length();
    memset(pi,0,sizeof(pi));
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j>0&&ss[i]!=ss[j])j=pi[j-1];
        if(ss[i]==ss[j])j++;
        pi[i]=j;
    }
}
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
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
        int n,m;
        cin>>n>>m;
        string s[2];
        cin>>s[0]>>s[1];
        memset(cnt,0,sizeof(cnt));
        for(char ch:s[0]){
            if(ch=='R')cnt[0][0]++;
            else cnt[0][1]++;
        }
        for(char ch:s[1]){
            if(ch=='R')cnt[1][0]++;
            else cnt[1][1]++;
        }
        memset(f,0,sizeof(f));
        for(int i=0;i<=1;i++){
            for(int j=0;j<=1;j++){
                con[i][j].clear();
                ss=s[j]+s[i];
                prefix_function();
                int len=ss.length();
                int k=pi[len-1];
                con[i][j].push_back(0);
                while(k){
                    if(k>=min(s[i].length(),s[j].length())){
                        k=pi[k-1];
                        continue;
                    }
                    con[i][j].push_back(k);
                    k=pi[k-1];
                }
            }
        }
        // f[0][0][0]=f[0][0][1]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0&&i==0)continue;
                for(int now=0;now<=1;now++){
                    for(int pre=0;pre<=1;pre++){
                        for(int k:con[pre][now]){
                            int x=i-cnt[now][0],y=j-cnt[now][1];
                            if(k==0&&x==0&&y==0){
                                f[i][j][now]++;
                                continue;
                            }
                            if(x<0||y<0)continue;
                            for(int l=0;l<k;l++){
                                if(s[now][l]=='R'){
                                    x++;
                                }else{
                                    y++;
                                }
                            }
                            f[i][j][now]=(f[i][j][now]+f[x][y][pre])%mod;
                        }
                    }
                }
            }
        }
        cout<<(f[n][m][1]+f[n][m][0])%mod<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}