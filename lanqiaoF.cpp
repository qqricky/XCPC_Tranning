#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[1070][1070]={};
ll a[1070][1070];
ll getsum(int x1,int y1,int x2,int y2){
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            sum[i][j]=(sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j]);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int a=i;a<=n;a++){
                for(int b=j;b<=m;b++){
                    if(getsum(i,j,a,b)<=k){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
    //cout.flush();
    //system("pause");
    return 0;
}