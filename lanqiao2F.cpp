#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
bool f[400][5070];
bool g[5070];
int mth[100]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sum[100];
vector<int>mp[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=1;i<=12;i++){
        sum[i]=sum[i-1]+mth[i];
    }
    int n,m,k;
    cin>>n>>m>>k;
    g[0]=1;
    for(int i=1;i<=n;i++){
        int x,y,v;
        cin>>x>>y>>v;
        mp[sum[x-1]+y].push_back(v);
    }
    int ans=0;
    for(int i=1;i<=365;i++){
        if(i-k>0){
            for(int j=1;j<=m;j++){
                g[j]|=f[i-k][j];
            }
        }
        for(int j=0;j<=m;j++){
            f[i][j]=g[j];
        }
        for(auto val:mp[i]){
            for(int j=m;j>=val;j--){
                f[i][j]|=f[i][j-val];
                if(f[i][j])ans=max(ans,j);
            }
        }
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}