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
    int l,r,h;
    bool operator <(const node &b)const{
        return h>b.h;
    }
}nd[N];
bool cmp(node a,node b){
    return a.h>b.h;
}
ll f[N][2];
int x,y,h;
int n;
int main()
{
    //freopen("C:/Users/14254/Downloads/P1442_2.in","r",stdin);
    //freopen("C:/Users/14254/Downloads/P1442_2.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>h>>x>>y;
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        cin>>nd[i].h>>nd[i].l>>nd[i].r;
    }
    sort(nd+1,nd+n+1,cmp);
    int st=0;
    for(int i=1;i<=n;i++){
        if(nd[i].h<=y&&nd[i].l<=x&&nd[i].r>=x){
            st=i;
            break;
        }
    }
    if(!st){
        cout<<y;
        return 0;
    }
    f[st][0]=y-nd[st].h+abs(x-nd[st].l);
    f[st][1]=y-nd[st].h+abs(x-nd[st].r);
    ll ans=INF;
    for(int i=st;i<=n;i++){
        bool fl=1;
        if(f[i][0]>=INF)continue;
        for(int j=i+1;j<=n;j++){
            if(nd[i].h-nd[j].h>h){
                fl=0;
                break;
            }
            if(nd[j].l<=nd[i].l&&nd[j].r>=nd[i].l){
                f[j][0]=min(f[j][0],nd[i].h-nd[j].h+abs(nd[i].l-nd[j].l)+f[i][0]);
                f[j][1]=min(f[j][1],nd[i].h-nd[j].h+abs(nd[i].l-nd[j].r)+f[i][0]);
                fl=0;
                break;
            }
        }
        if(fl&&(nd[i].h<=h))ans=min(ans,f[i][0]+nd[i].h);
        fl=1;
        for(int j=i+1;j<=n;j++){
            if(nd[i].h-nd[j].h>h){
                fl=0;
                break;
            }
            if(nd[j].l<=nd[i].r&&nd[j].r>=nd[i].r){
                f[j][0]=min(f[j][0],nd[i].h-nd[j].h+abs(nd[i].r-nd[j].l)+f[i][1]);
                f[j][1]=min(f[j][1],nd[i].h-nd[j].h+abs(nd[i].r-nd[j].r)+f[i][1]);
                fl=0;
                break;
            }
        }
        if(fl&&(nd[i].h<=h))ans=min(ans,f[i][1]+nd[i].h);
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}