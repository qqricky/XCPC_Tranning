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
struct node
{
    int a,b;
    int id;
}ra[N],rb[N];
bool cmp1(node x,node y){
    return x.a<y.a;
}
bool cmp2(node x,node y){
    return x.b<y.b;
}
bool vis[N]={};
int vala,valb,posa,posb;
void dfs(int var){
    bool flag=0;
    if(var){
        while(rb[posb].b>valb){
            vis[rb[posb].id]=1;
            if(rb[posb].a<vala){
                flag=1;
                vala=rb[posb].a;
            }
            posb--;
        }
    }
    else{
        while(ra[posa].a>vala){
            vis[ra[posa].id]=1;
            if(ra[posa].b<valb){
                flag=1;
                valb=ra[posa].b;
            }
            posa--;
        }
    }
    if(flag){
        dfs(var^1);
    }
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
    while(t--){
        int n;
        cin>>n;
        memset(vis,0,sizeof(vis[0])*(n+2));
        for(int i=1;i<=n;i++){
            cin>>ra[i].a;
            ra[i].id=i;
        }
        for(int i=1;i<=n;i++){
            cin>>ra[i].b;
            rb[i]=ra[i];
        }
        sort(ra+1,ra+n+1,cmp1);
        sort(rb+1,rb+n+1,cmp2);
        vis[ra[n].id]=1;
        vala=ra[n].a,valb=ra[n].b;
        posa=n,posb=n;
        dfs(1);
        for(int i=1;i<=n;i++){
            cout<< vis[i] ? 1 : 0;
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}