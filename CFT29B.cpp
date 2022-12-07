#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
const int up=300000;
int c[N]={};
void add(int x,int y){
    for(int i=x;i<=up;i+=(i&-i)){
        c[i]+=y;
    }
}
int ask(int p){
    int res=0;
    for(int i=p;i;i-=i&-i){
        res+=c[i];
    }
    return res;
}
struct node
{   
    int a,p,f;
    int rk;
};
vector<node>nd[N];
vector<int>pos[N];
int xx[N];
int ans[N]={};
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int y,n;
    cin>>y>>n;
    for(int i=1;i<=y;i++){
        int x;
        cin>>x;
        xx[i]=x;
        pos[x].push_back(i);
    }
    for(int i=1;i<=n;i++){
        node tmp;
        cin>>tmp.a>>tmp.p>>tmp.f;
        tmp.rk=i;
        nd[tmp.p].push_back(tmp);
    }
    int k=y;
    for(int i=1e5;i>=1;i--){
        for(int x:pos[i]){
            //cout<<"pos "<<x<<' '<<k<<endl;
            add(x,1);
        }
        for(node x:nd[i]){
            if(x.p>xx[x.a])
            ans[x.rk]=ask(x.a+x.f)-ask(x.a);
            //cout<<"lalaa  ";
            //cout<<x.rk<<endl;
            //cout<<ans[x.rk]<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}