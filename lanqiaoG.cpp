#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e7+10;
ll f[N];
const ll mod=1e9+7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(i>=2){
            f[i]=(f[i]+f[i-2])%mod;
        }
        if(i>=3){
            f[i]=(f[i]+f[i-3]*2%mod)%mod;
        }
        f[i]=(f[i]+f[i-1])%mod;
    }
    cout<<f[n]%mod;
    //cout.flush();
    //system("pause");
    return 0;
}