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
int v[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++){
        int u,x;
        cin>>u>>x;
        if(u>x)swap(u,x);
        v[u]++;
    }
    for(int i=1;i<=n;i++)if(!v[i])ans++;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int op,x,y;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            if(x>y)swap(x,y);
            v[x]++;
            if(v[x]==1)ans--;
        }
        else if(op==2){
            cin>>x>>y;
            if(x>y)swap(x,y);
            v[x]--;
            if(!v[x])ans++;
        }
        else{
            cout<<ans<<'\n';
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}