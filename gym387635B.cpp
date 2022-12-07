#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
set<int>s[570];
bool vis[570][570]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=n*m*n*m/2;
    for(int i=1;i<=n*m;i++){
        int x,y;
        cin>>x>>y;
        int st=x;
        while(!vis[st][y]&&st>=1){
            st--;
        }
        st++;
        int ed=x;
        while(!vis[ed][y]&&ed<=n){
            ed++;
        }
        ed--;
        ll ans;
        for(int i=st;i<=ed;i++){
            
        }
        s[x].insert(y);
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}