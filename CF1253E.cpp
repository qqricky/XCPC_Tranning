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
int f[100][N];
struct node{
    int x,s;
    bool operator <(const node &a){
        if(x==a.x){
            return s>a.s;
        }
        return x<a.x;
    }
}nd[100];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)cin>>nd[i].x>>nd[i].s;
    sort(nd+1,nd+n+1);
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        int val=min(f[i-1][max(0,nd[i].x-nd[i].s-1)],max(0,nd[i].x-nd[i].s-1));
        for(int j=0;j<=m;j++){
            if(nd[i].x+nd[i].s<j){
                f[i][j]=min(f[i-1][j],f[i-1][max(2*nd[i].x-j-1,0)]+j-nd[i].x-nd[i].s);
                if(j<=2*nd[i].x-1){
                    f[i][j]=min(f[i][j],nd[i].x-nd[i].s-1);
                }
            }
            else if(j>=nd[i].x-nd[i].s){
                val=min(val,f[i-1][j]);
                f[i][j]=min(f[i-1][j],val);
            }
            else{
                f[i][j]=min(f[i-1][j],max(0,nd[i].x-nd[i].s-1));
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(f[i][j]!=INF){
    //             cout<<" ("<<j<<' '<<f[i][j]<<' '<<")";
    //         }
    //     }
    //     cout<<endl;
    // }
    cout<<f[n][m];
    cout.flush();
    //system("pause");
    return 0;
}