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
int pos[N];
int ne[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[i]=n+1;
    }
    for(int i=n;i>=1;i--){
        ne[i]=pos[a[i]];
        pos[a[i]]=i;
    }
    ll ans=0;
    set<int>s;
    s.insert(a[1]);
    int r=n+1;
    for(int i=2;i<=n;i++){
        s.insert(a[i]);
        if(s.size()==m){
            r=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(r>n)break;
        ans+=n-r+1;
        int x=ne[i];
        if(x>r)r=x;
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}