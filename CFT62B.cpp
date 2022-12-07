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
int n,m;
int tp[N];
bool is1no0[N];
bool is0no1[N];
vector<int>mp[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int num0=0;
    int num1=0;
    for(int i=1;i<=n;i++){
        cin>>tp[i];
        num1+=tp[i];
    }
    num0=n-num1;
    int num0no1=0;
    int num1no0=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(tp[i]){
            bool is=1;
            for(int v:mp[i]){
                if(tp[v]==0)is=0;
            }
            if(is){
                num1no0++;
                is1no0[i]=1;
            }
        }else{
            bool is=1;
            for(int v:mp[i]){
                if(tp[v]==1)is=0;
            }
            if(is){
                num0no1++;
                is0no1[i]=1;
            }
        }
    }
    // num1-=num1no0;
    // num0-=num0no1;
    for(int i=1;i<=n;i++){
        int ans=0;
        if(tp[i]){
            ans+=num1-1;
            int cnt0=num0;
            for(int x:mp[i]){
                if(tp[x]==0){
                    ans++;
                    cnt0--;
                }
            }
            if(is1no0[i]){
                ans+=num0no1*3;
                ans+=(cnt0-num0no1)*2;
            }else{
                ans+=cnt0*2;
            }
        }else{
            ans+=num0-1;
            int cnt1=num1;
            for(int x:mp[i]){
                if(tp[x]){
                    ans++;
                    cnt1--;
                }
            }
            if(is0no1[i]){
                ans+=num1no0*3;
                ans+=(cnt1-num1no0)*2;
            }else{
                ans+=cnt1*2;
            }
        }
        cout<<ans<<' ';
    }
    // cout.flush();
    // system("pause");
    return 0;
}