#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10;
using namespace std;
struct node{
    int val;
    int pos;
};
bool operator < (const node &x,const node &y){
    return x.val<y.val;
}
int v[N]={};
int p[N];
int lf[N];
int rt[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    priority_queue<node>q;
    ll ans=0;
    int tmp;
    p[0]=0;
    for(int i=1;i<=n;i++){
        lf[i]=i-1;
        rt[i]=i+1;
        cin>>tmp;
        p[i]=tmp;
        q.push((node){tmp,i});
    }
    for(int j=1;j<=k;j++){
        node x=q.top();
        while(v[x.pos]==1){
            q.pop();
            x=q.top();
        }
        q.pop();
        //cout<<x.pos<<'q'<<x.val<<endl;
        if(x.val<0)break;
        ans+=x.val;
        v[x.pos]=0;
        v[rt[x.pos]]=1;
        v[lf[x.pos]]=1;
        p[x.pos]=p[lf[x.pos]]+p[rt[x.pos]]-p[x.pos];
        q.push((node){p[x.pos],x.pos});
        lf[x.pos]=lf[lf[x.pos]];
        rt[x.pos]=rt[rt[x.pos]];
        rt[lf[x.pos]]=x.pos;
        lf[rt[x.pos]]=x.pos;
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}