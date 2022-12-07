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
int c[N];
int b[N]={};
struct node
{
    int l,r;
}nd[N];
bool cmp(node x,node y){
    return (x.r-x.l)<(y.r-y.l);
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>c[i];
        b[i]=c[i];
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)swap(x,y);
        nd[i].l=++x;
        nd[i].r=++y;
    }
    sort(nd+1,nd+q+1,cmp);
    int ans=0;
    for(int i=1;i<=q;i++){
        int mi=INF;
        //cout<<"ajksd ";
        //cout<<nd[i].l<<' '<<nd[i].r<<endl;
        for(int j=nd[i].l;j<nd[i].r;j++){
            mi=min(mi,c[j]);
        }
        for(int j=nd[i].l;j<nd[i].r;j++){
            c[j]-=mi;
        }
        //cout<<mi<<endl;
        ans+=mi;
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}