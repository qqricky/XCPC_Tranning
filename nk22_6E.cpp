#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
vector<pair<int,int> >l[N];
struct node
{
    int x,id;
}nd[N];
bool cmp(node a,node b){
    return a.x>b.x;
}
int b[N];
struct node2
{
    int r,id,ff;
    bool operator<(const node2 &c)const{
        if(ff!=c.ff)return ff>c.ff;
        return r>c.r;
    }
};
int fst[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    memset(fst,0x3f,sizeof(fst));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nd[i].x;
        ll y=1;
        while(y<=nd[i].x){
            y<<=1;
        }
        // y>>=1;
        // nd[i].x=y;
        nd[i].id=i;
    }
    sort(nd+1,nd+n+1,cmp);
    int mx=nd[1].x;
    // mx<<=1;
    int nmx=0;
    for(int i=1;i<=n;i++){
        int now=1;
        int len=nd[i].x;
        while(now<=mx){
            l[now].push_back(make_pair((nd[i].x),nd[i].id));
            now+=len;
            nmx=max(nmx,now-1);
        }
    }
    cout<<mx<<'\n';
    priority_queue<node2>q;
    for(int i=1;i<=mx;i++){
        for(auto pr:l[i]){
            q.push((node2){pr.first,pr.second,fst[pr.second]});
        }
        if(q.size()){
            auto d=q.top();
            q.pop();
            b[i]=d.id;
            fst[d.id]=min(fst[d.id],i);
        }else{
            b[i]=1;
        }
    }
    for(int i=1;i<=mx;i++){
        cout<<b[i]<<' ';
    }
    // cout.flush();
    // system("pause");
    return 0;
}