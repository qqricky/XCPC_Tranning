#include<bits/stdc++.h>
#pragma GCC optimise(2);
#define N 500005
using namespace std;
int n,m; 
int fa[N],ch[N][2],size[N],rev[N],rt;
inline void pushup(int x){
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void pushdown(int x){
    if(rev[x]){
        swap(ch[x][0],ch[x][1]);
        rev[ch[x][0]]^=1;rev[ch[x][1]]^=1;rev[x]=0;
    }
}
void rotate(int x,int &k){
    int y=fa[x],z=fa[y],kind;
    if(ch[y][0]==x)kind=1;else kind=0;
    if(y==k)k=x;
    else{if(ch[z][0]==y)ch[z][0]=x;else ch[z][1]=x;}
    ch[y][kind^1]=ch[x][kind];fa[ch[y][kind^1]]=y;
    ch[x][kind]=y;fa[y]=x;fa[x]=z;
    pushup(x);pushup(y);
}
void splay(int x,int &k){
    while(x!=k){
        int y=fa[x],z=fa[y];
        if(y!=k){
            if((ch[y][0]==x)^(ch[z][0]==y))rotate(x,k);
            else rotate(y,k);
        }
        rotate(x,k);
    }
}
void build(int l,int r,int f){
    if(l>r)return;
    int mid=(l+r)/2;
    if(mid<f)ch[f][0]=mid;else ch[f][1]=mid;
    fa[mid]=f;size[mid]=1;
    if(l==r)return;
    build(l,mid-1,mid);build(mid+1,r,mid);
    pushup(mid);
}
int find(int x,int k){
    pushdown(x);int s=size[ch[x][0]];
    if(k==s+1)return x;
    if(k<=s)return find(ch[x][0],k);
    else return find(ch[x][1],k-s-1);
}
void rever(int l,int r){
    int x=find(rt,l),y=find(rt,r+2);
    splay(x,rt);splay(y,ch[x][1]);int z=ch[y][0];
    rev[z]^=1;
}
char str[N];
int main(){
    scanf("%d %d",&n,&m);
    scanf("%s",str+1);
    rt=(n+3)/2;build(1,n+2,rt);
    for(int i=1;i<=m;i++){
        int L,R;
        L=1;
        scanf(" %d",&R);
        rever(L,R);
    }
    for(int i=2;i<=n+1;i++)printf("%c",str[find(rt,i)-1]);
    //cout.flush();
    //cout<<(double)clock()/CLOCKS_PER_SEC<<endl;
    //system("pause");
    return 0;
}