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
int xx[10070];
int yy[10070];
int fa[N];
int len[N];
int getfa(int x){
    return x==fa[x] ? x : fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
    x=getfa(x);
    y=getfa(y);
    if(x>y)swap(x,y);
    fa[x]=y;
}
double dis(int a,int b){
    return sqrt((xx[a]-xx[b])*(xx[a]-xx[b])+(yy[a]-yy[b])*(yy[a]-yy[b]));
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>m>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>xx[i]>>yy[i]>>len[i];
    }
    for(int i=1;i<=k+4;i++){
        fa[i]=i;
    }
    for(int i=1;i<=k;i++){
        if(xx[i]<=len[i])merge(i,1+k);
        if(m-xx[i]<=len[i])merge(i,3+k);
        if(yy[i]<=len[i])merge(i,4+k);
        if(n-yy[i]<=len[i])merge(i,2+k);
        for(int j=i+1;j<=k;j++){
            if(dis(i,j)<=len[i]+len[j]){
                merge(i,j);
            }
        }
    }
    set<int>s;
    s.insert(getfa(1+k));
    s.insert(getfa(2+k));
    bool flag=1;
    if(s.count(getfa(3+k)))flag=0;
    if(s.count(getfa(4+k)))flag=0;
    if(flag)cout<<"S";
    else cout<<"N";
    cout.flush();
    //system("pause");
    return 0;
}