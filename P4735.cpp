#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
int p[N][40]={};
int pos[N][40]={};
int ncnt=0;
int ans=0;
void add(int x)
{
    ncnt++;
    for(int i=30;i>=0;i--)p[ncnt][i]=p[ncnt-1][i];
    for(int i=30;i>=0;i--)pos[ncnt][i]=pos[ncnt-1][i];
    int poss=ncnt;
    for(int i=30;i>=0;i--){
        if(x&(1ll<<i)){
            if(!p[ncnt][i]){
                p[ncnt][i]=x;
                pos[ncnt][i]=poss;
                return;
            }
            if(pos[ncnt][i]<poss){
                swap(pos[ncnt][i],poss);
                swap(p[ncnt][i],x);
            }
            x^=p[ncnt][i];
        }
    }
    return ;
}
void solve(int l,int r)
{
    int tt=0;
    for(int i=30;i>=0;i--){
        if(pos[r][i]<l)continue;
        tt=max(tt,tt^p[r][i]);
    }
    cout<<tt<<endl;
    ans=tt;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ncnt=0;
        int n,m;
        cin>>n>>m;
        int tmp;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            add(tmp);
        }
        int l,r;
        int vir;
        for(int i=1;i<=m;i++){
            cin>>vir;
            if(vir){
                cin>>tmp;
                tmp^=ans;
                add(tmp);
            }
            else{
                cin>>l>>r;
                l=(l^ans)%ncnt+1;
                r=(r^ans)%ncnt+1;
                if(l>r)swap(l,r);
                solve(l,r);
            }
        }
    }
    //system("pause");
    return 0;
}