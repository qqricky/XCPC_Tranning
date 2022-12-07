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
int c[N];
int n;
void add(int pos,int val){
    for(int i=pos;i<=n;i+=(i&-i)){
        c[i]+=val;
    }
}
vector<int>lev[100];
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
        cin>>n;
        memset(c,0,sizeof(int)*(n+10));
        for(int i=0;i<=64;i++)lev[i].clear();
        string str;
        cin>>str;
        str=' '+str;
        int ans=0;
        for(int i=1;i<=n;i++){
            int lb=(i&-i);
            int cnt=0;
            while(lb){
                cnt++;
                lb>>=1;
            }
            lev[cnt].push_back(i);
        }
        for(int i=1;i<=64;i++){
            for(int x:lev[i]){
                if(str[x]=='1'){
                    if(c[x]==0){
                        ans++;
                        add(x,1);
                    }else{
                        add(x,-(c[x]-1));
                    }
                }else{
                    if(c[x]==1)ans++;
                    add(x,-c[x]);
                }
            }
        }
        cout<<ans<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}