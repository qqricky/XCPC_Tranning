#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
ll n,x;
ll f[(1<<12)][50]={};
int ans=INF;
void dfs(ll now,int step){
    if(step>=ans)return;
    int len=0;
    ll tmp=now;
    set<int>s;
    while(tmp){
        s.insert(tmp%10);
        tmp/=10;
        len++;
    }
    if(len>=n){
        ans=min(ans,step);
        return;
    }
    
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>x;
    // if(x==1&&n!=1){
    //     cout<<-1;
    //     return 0;
    // }
    // dfs(x,0);
    set<int>s;
    ll tmp=x;
    while(tmp){
        s.insert(tmp%10);
        tmp/=10;
    }
    int sta=0;
    for(int x:s){
        sta+=(1<<x);
    }
    f[sta][0]=x;
    for(int k=0;k<=30;k++){
        for(int i=0;i<=(1<<10);i++){
            ll x=f[i][k];
            s.clear();
            tmp=x;
            while(tmp){
                s.insert(tmp%10);
                tmp/=10;
            }
            for(int y:s){
                if(y>1){
                    ll ne=x*y;
                    if(ne>=1e18)break;
                    set<int>ss;
                    tmp=ne;
                    int len=0;
                    while(tmp){
                        ss.insert(tmp%10);
                        tmp/=10;
                        len++;
                    }
                    int sta=0;
                    for(int x:ss){
                        sta+=(1<<x);
                    }
                    f[sta][k+1]=max(f[sta][k+1],ne);
                    if(len>=n){
                        ans=min(ans,k+1);
                    }
                }
            }
        }
        if(k==30){
            ans=-1;
            break;
        }
    }
    ed:;
    cout<<ans;
    cout.flush();
    system("pause");
    return 0;
}