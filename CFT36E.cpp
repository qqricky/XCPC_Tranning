#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
const int M=N*30;
using namespace std;
int n,q,m,tot;
int a[N],t[N];
int T[N],lson[M],rson[M],c[M];
void init_hash(){
    for(int i=1;i<=n;i++)t[i]=a[i];
    sort(t+1,t+n+1);
    m=unique(t+1,t+n+1)-t-1;
}
int built(int l,int r){
    int root=tot++;
    c[root]=0;
    if(l!=r){
        int mid=(l+r)>>1;
        c[root]=0;
        if(l!=r){
            int mid=(l+r)>>1;
            lson[root]=built(l,mid);
            rson[root]=built(mid+1,r);
        }
        return root;
    }
}
int hash(int x){
    return lower_bound(t+1,t+1+m,x)-t;
}
int update(int root,int pos,int val){
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(pos<=mid){
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else{
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int root,int k){
    int l=1,r=m;
    while(l<r){
        int mid=(l+r)>>1;
        if(mid>=k){
            r=mid;
            root=lson[root];
            root=lson[root];
        }
        else{
            l=mid+1;
            root=rson[root];
            root=rson[root];
        }
    }
    return c[root];
}
int d[N];
vector<int>pos[N][2];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch;
        int x;
        cin>>ch>>x;
        T[i]=tot+1;
        if(ch=='+'){
            update(T[i-1],x,1);
        }
        else{
            update(T[i-1],x,-1);
        }
        cin>>ch>>x;
        if(ch=='+'){
            update(T[i-1],x,1);
        }
        else{
            update(T[i-1],x,-1);
        }
    }
    ll x=0;
    for(int i=1;i<=n;i++){
        cin>>d[i];
        //cout<<i<<' '<<query(T[d[i]],x);
        //cout<<' '<<query(T[d[i]],1e5)<<endl;
        if(x==0){
            x=(x+query(T[d[i]],1e5))%n;
        }
        else{
            x=(x+query(T[d[i]],1e5)-query(T[d[i]],x-1))%n;
        }
    }
    cout<<x;
    cout.flush();
    //system("pause");
    return 0;
}