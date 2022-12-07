#include<bits/stdc++.h>
#pragma GCC optimise(2)
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=4e5+10;
struct Splay
{
    int ch[maxn][2],fa[maxn],tag[maxn];

    void clear(int x){
        ch[x][0]=ch[x][1]=fa[x]=tag[x]=0;
    }
    int getch(int x){
        return ch[fa[x]][1]==x;
    }
    int isroot(int x){
        return ch[fa[x]][0]!=x && ch[fa[x]][1]!=x;
    }
    void pushdown(int x){
        if(tag[x]){
            if(ch[x][0])swap(ch[ch[x][0]][0],ch[ch[x][0]][1]),tag[ch[x][0]]^=1;
            if(ch[x][1])swap(ch[ch[x][1]][0],ch[ch[x][1]][1]),tag[ch[x][1]]^=1;
            tag[x]=0;
        }
    }
    void update(int x){
        if(!isroot(x))update(fa[x]);
        pushdown(x);
    }
    void rotate(int x){
        int y=fa[x],z=fa[y],chx=getch(x),chy=getch(y);
        fa[x]=z;
        if(!isroot(y))ch[z][chy]=x;
        ch[y][chx]=ch[x][chx^1];
        fa[ch[x][chx^1]]=y;
        ch[x][chx^1]=y;
        fa[y]=x;
    }
    void splay(int x){
        update(x);
        for(int f=fa[x];f=fa[x],!isroot(x);rotate(x))
            if(!isroot(f))rotate(getch(x)==getch(f) ? f:x);
    }
    void access(int x){
        for(int f=0;x;f=x,x=fa[x])splay(x),ch[x][1]=f;
    }
    void makeroot(int x){
        access(x);
        splay(x);
        swap(ch[x][0],ch[x][1]);
        tag[x]^=1;
    }
    int find(int x){
        access(x);
        splay(x);
        while(ch[x][0])x=ch[x][0];
        splay(x);
        return x;
    }
    void cut(int x,int y){
        makeroot(x);
        access(y);
        splay(y);
        if(ch[y][0]==x&&!ch[x][1])ch[y][0]=fa[x]=0;
    }
    void link(int x,int y){
        if(find(x)!=find(y)){
            makeroot(x);
            fa[x]=y;
        }
    }
}st;
int n,m,q,x,y;
int ncnt=0;
set<int>s[maxn];
int nxt[maxn];
map<pair<int,int> ,int>mp;
void init(){
    ncnt=2*n;
    for(int i=1;i<=n;i++){
        s[i].insert(0);
        nxt[n+i]=i;
        mp[make_pair(i,0)]=n+i;
        mp[make_pair(i,m+1)]=i;
        s[i].insert(m+1);
        st.link(n+i,i);
        st.makeroot(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    init();
    for(int i=1;i<=q;i++){
        int op;
        cin>>op;
        if(op==1){
            cin>>x>>y;
            int nx=x+1;
            int ny=y;
            auto it1=s[x].lower_bound(y);
            auto it11=it1;
            it11--;
            auto it2=s[nx].lower_bound(y);
            auto it22=it2;
            it22--;
            int a1=*it11;
            // int a2=*it1;
            int b1=*it22;
            // int b2=*it2;
            int x1=mp[make_pair(x,a1)];
            int x2=nxt[x1];
            // int x2=mp[make_pair(x,a2)];
            int y1=mp[make_pair(x+1,b1)];
            int y2=nxt[y1];
            // int y2=mp[make_pair(x+1,b2)];
            int n1=++ncnt;
            int n2=++ncnt;
            mp[make_pair(x,y)]=n1;
            mp[make_pair(x+1,y)]=n2;
            int rt1=st.find(x2);
            int rt2=st.find(y2);
            nxt[x1]=n1;
            nxt[x2]=n2;
            nxt[n1]=y2;
            nxt[n2]=x2;
            st.cut(x1,x2);
            st.cut(y1,y2);
            st.link(x1,n1);
            st.link(n1,y2);
            st.link(y1,n2);
            st.link(n2,x2);
            st.makeroot(rt1);
            st.makeroot(rt2);
            s[x].insert(y);
            s[x+1].insert(y);
        }else{
            cin>>x;
            cout<<st.find(x+n)<<'\n';
        }
    }
    cout.flush();
    system("pause");
    return 0;
}