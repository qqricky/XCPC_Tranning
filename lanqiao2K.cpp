#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
double p[100][100];
double f[100];
double base[100];
struct node
{
    double p;
    int id;
}nd[N];
bool cmp(node a,node b){
    if(fabs(a.p-b.p)<1e-5){
        return a.id<b.id;
    }
    return a.p>b.p;
}
bool vis[N]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        base[i]=x*1.0/100;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            p[i][j]=x*1.0/100;
        }
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        vis[x]=1;
    }
    double sum=0;
    for(int i=1;i<=n;i++){
        double val=base[i];
        for(int j=1;j<=m;j++){
            if(vis[j]){
                val*=p[i][j];
            }else{
                val*=(1-p[i][j]);
            }
        }
        f[i]=val;
        sum+=val;
    }
    for(int i=1;i<=n;i++){
        nd[i].id=i;
        nd[i].p=f[i]/sum;
    }
    sort(nd+1,nd+n+1,cmp);
    for(int i=1;i<=n;i++){
        cout<<nd[i].id<<' '<<fixed<<setprecision(2)<<(nd[i].p*100)<<'\n';
    }
    // cout.flush();
    // system("pause");
    return 0;
}