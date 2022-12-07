#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int n;
int ne[N];
int fa[N];
int getfa(int x){
    return x==fa[x] ? x : fa[x]=getfa(fa[x]);
}
// int getne(int x){
//    int st=x;
//    st=getfa(st);
//    while(getfa(x)==st){
//        x=ne[x];
//        if(x==n)break;
//    }
//    ne[st]=x;
//    return ne[st];
// }
int getne(int x){
   int st=x;
   st=getfa(st);
   int nxt=ne[x];
   if(st!=getfa(nxt))return nxt;
   else return ne[x]=getne(ne[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x>y)swap(x,y);
    fa[x]=y;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        fa[i]=i;
        ne[i]=i+1;
    }
    ne[n]=n;
    while(m--){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            int xx=getfa(x);
            int yy=getfa(y);
            merge(xx,yy);
            getne(x);
        }
        else if(op==2){
            for(int i=x;i<=y;i=getne(i)){
                merge(x,i);
            }
        }
        else{
            x=getfa(x),y=getfa(y);
            if(x==y)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}