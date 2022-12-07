#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
int f[1070][2070];
struct node
{
    int v,w;
}nd[N];
bool cmp(node a,node b){
    if(a.v==b.v)return a.w<b.w;
    return a.v<b.v;
}
int c[N]={};
void change(int pos,int val){
    for(int i=pos;i<=30070;i+=(i&-i)){
        c[i]=max(c[i],val);
    }
}
int ask(int pos){
    int res=0;
    for(int i=pos;i;i-=(i&-i)){
        res=max(res,c[i]);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>nd[i].w>>nd[i].v;
    }
    sort(nd+1,nd+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=nd[i].w;j<=nd[i].v+nd[i].w;j++){
            f[i][j]=ask(j-nd[i].w)+nd[i].v;
        }
        for(int j=nd[i].w;j<=nd[i].v+nd[i].w;j++){
            change(j,f[i][j]);
        }
    }
    cout<<ask(3e4+10);
    // cout.flush();
    // system("pause");
    return 0;
}