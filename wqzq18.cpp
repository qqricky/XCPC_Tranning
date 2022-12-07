#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10;
using namespace std;
int priority[N]={};
struct order
{
    int t;
    int shop;
}nd[N];
int last[N]={};
bool is[N]={};
bool cmp(order a,order b){
    return a.t<b.t;
}
int main()
{
    int n,m,T;
    cin>>n>>m>>T;
    for(int i=1;i<=m;i++){
        cin>>nd[i].t>>nd[i].shop;
    }
    sort(nd+1,nd+m+1,cmp);
    nd[0].t=0;
    nd[n+1].t=T;
    for(int i=1;i<=m;i++){
        int duration=nd[i].t-nd[last[nd[i].shop]].t;
        last[nd[i].shop]=i;
        if(duration-1>=priority[nd[i].shop]){
            priority[nd[i].shop]=2;
        }
        else{
            priority[nd[i].shop]+=2+1-duration;
        }
        if(priority[nd[i].shop]>5)is[nd[i].shop]=1;
        if(priority[nd[i].shop]<=3)is[nd[i].shop]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int duration=nd[n+1].t-nd[last[i]].t;
        priority[i]-=duration;
        if(priority[i]>5)is[i]=1;
        if(priority[i]<=3)is[i]=0;
    }
    for(int i=1;i<=n;i++){
        ans+=is[i];
    }
    cout<<ans;
    //system("pause");
    return 0;
}