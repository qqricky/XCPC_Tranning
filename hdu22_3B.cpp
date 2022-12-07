#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
struct node
{
    int id,tp;
    ll x,y,w;
}nd[N];
ll ans[N];
ll w[N];
bool cmpx(node &a,node &b){
    return a.x<b.x;
}
bool cmpy(node &a,node &b){
    return a.y<b.y;
}
ll mxl[N];
ll sum[N];
ll mxr[N];
struct val
{   
    int v,w;
}nd1[N],nd2[N];
int ncnt1;
int ncnt2;
void CDQ(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1;
    CDQ(1,mid);CDQ(mid+1,r);
    sort(nd+l,nd+mid+1,cmpy);sort(nd+mid+1,nd+r+1,cmpy);
    


    int t1=l;
    int t2=mid+1;
    ll mi=-1e16;
    ncnt1=0;
    ncnt2=0;
    for(int i=mid+1;i<=r;i++){
        if(nd[i].tp==1){
            nd1[++ncnt1].v=nd[i].x+nd[i].y;
            nd1[++ncnt2].w;
        }
    }
    // for(int i=l;i<=r;i++){
    //     if(t1<=mid&&nd[t1].y<=nd[t2].y||t2>r){
    //         if(nd[t1].tp==1){
    //             mi=max(mi,-nd[t1].x-nd[t1].y);
    //         }
    //         t1++;
    //     }else{
    //         if(nd[t2].tp==2){
    //             ans[nd[t2].id]=max(ans[nd[t2].id],nd[t2].x+nd[t2].y+mi);
    //         }
    //         t2++;
    //     }
    // }



    t1=mid;
    t2=r;
    mi=-1e16;
    // for(int i=l;i<=r;i++){
    //     if(t1>=1&&nd[t1].y>=nd[t2].y||t2<mid+1){
    //         if(nd[t1].tp==1){
    //             mi=max(mi,-nd[t1].x+nd[t1].y);
    //         }
    //         t1--;
    //     }else{
    //         if(nd[t2].tp==2){
    //             ans[nd[t2].id]=max(ans[nd[t2].id],nd[t2].x-nd[t2].y+mi);
    //         }
    //         t2--;
    //     }
    // }



    t1=l;
    t2=mid+1;
    mi=-1e16;
    // for(int i=l;i<=r;i++){
    //     if(t2<=r&&nd[t1].y>=nd[t2].y||t1>mid){
    //         if(nd[t2].tp==1){
    //             mi=max(mi,nd[t2].x-nd[t2].y);
    //         }
    //         t2++;
    //     }else{
    //         if(nd[t1].tp==2){
    //             ans[nd[t1].id]=max(ans[nd[t1].id],-nd[t1].x+nd[t1].y+mi);
    //         }
    //         t1++;
    //     }
    // }




    t1=mid;
    t2=2;
    mi=-1e16;
    // for(int i=l;i<=r;i++){
    //     if(t2>=mid+1&&nd[t1].y<=nd[t2].y||t1<l){
    //         if(nd[t2].tp==1){
    //             mi=max(mi,nd[t2].x+nd[t2].y);
    //         }
    //         t2--;
    //     }else{
    //         if(nd[t1].tp==2){
    //             ans[nd[t1].id]=max(ans[nd[t1].id],-nd[t1].x-nd[t1].y+mi);
    //         }
    //         t1--;
    //     }
    // }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++){
            cin>>nd[i].x>>nd[i].y>>nd[i].w;
            nd[i].tp=1;
        }
        for(int i=1;i<=q;i++){
            ans[i]=0;
            cin>>nd[i+n].x>>nd[i+n].y;
            nd[i+n].id=i;
            nd[i+n].tp=2;
        }
        sort(nd+1,nd+q+n+1,cmpx);
        CDQ(1,n+q+1);
        for(int i=1;i<=q;i++){
            cout<<ans[i]<<'\n';
        }
    }
    cout.flush();
    system("pause");
    return 0;
}