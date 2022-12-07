#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ll long long
const ll mod=1e9+7;
ll f[2][410][410]={};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int k=n+m;
    f[0][2][0]=1;
    ll ans=0;
    for(int i=1;i<k;i++){
        int now=i&1;
        for(int j=0;j<=400;j++){
            for(int d=0;d<=i;d++){
                f[now][j][d]=0;
                if(d!=i){
                    f[now][j][d]=(f[now][j][d]+f[now^1][j+1][d])%mod;
                }
                if(d>0&&(j%2==0)){
                    f[now][j][d]=(f[now][j][d]+f[now^1][j/2][d-1])%mod;
                }
                // if(f[now][j][d]>0){
                //     cout<<"! ";
                //     cout<<i<<' '<<j<<' '<<d<<endl;
                //     cout<<"---> "<<f[now][j][d]<<endl;
                // }
            }
        }
    }
    int now=(k-1)&1;
    cout<<f[now][1][n]%mod;
    //cout.flush();
    //system("pause");
    return 0;
}