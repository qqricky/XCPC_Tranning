#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
const ll mod=1e9+7;
ll fac[N];
ll f[210][210][210]={};
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
ll c(ll n,ll m){
    return fac[n]*powq(fac[n-m],mod-2)%mod*powq(fac[m],mod-2);
}
void init(){
    fac[0]=1;
    for(int i=1;i<=1e5;i++){
        fac[i]=(fac[i-1]*i)%mod;
    }
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--){
        int n,m;
        cin>>n>>m;
        string str;
        cin>>str;
        str=' '+str;
        ll ans=1;
        int x=0;
        int cnt1=0;
        int cnt2=0;
        for(char ch:str){
            if(ch=='(')cnt1++;
            else if(ch==')')cnt2++;
        }
        for(int i=0;i<=m;i++)for(int j=0;j<=n;j++)for(int h=0;h<=200;h++)f[i][j][h]=0;
        f[0][0][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(j>0){
                    for(int k=200;k>=0;k--){
                        if(str[j]=='('){
                            f[i][j][k]=(f[i-1][j-1]);
                        }
                    }
                }
                for(int k=200;k>=0;k--){
                    if(j>0){
                        if(str[j]=='('){
                            if(k-2>=0)
                            f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k-2])%mod;
                            f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
                        }else{
                            f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k+2])%mod;
                            if(k>0)
                            f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
                        }
                    }else{
                        f[i][j][k]=(f[i][j][k]+f[i-1][j][k+1])%mod;
                        if(k-1>=0)
                        f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1])%mod;
                    }
                }
                // for(int k=0;k<=200;k++){
                //     // if(j+k==0)continue;
                //     // if(str[j]=='('){
                //     //     f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
                //     // }else{
                //     //     f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k+2])%mod;
                //     // }
                //     f[i][j][k]=(f[i][j][k]+f[i-1][j][k+1])%mod;
                //     if(k-1>=0)
                //     f[i][j][k]=(f[i][j][k]+f[i-1][j][k-1])%mod;
                //     if(f[i][j][k]>0)
                //     cout<<i<<' '<<j<<' '<<k<<" :  "<<f[i][j][k]<<'\n';
                // }
                // for(int k=200;k>=0;k--){
                //     if(j>0){
                //         if(str[j]=='('){
                //             if(k-1>=0)
                //             f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k-1])%mod;
                //         }else{
                //             f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k+1])%mod;
                //         }
                //     }
                // }
            }
            // for(int j=1;j<=n;j++){
            //     for(int k=200;k>=0;k--){
            //     }
            // }
        }
        cout<<f[m][n][0]<<'\n';
        // for(int i=1;i<=n;i++){
        //     if(str[i]=='('){
        //         x++;
        //     }else{
        //         x--;
        //         if(x<0){
        //             x++;
        //             ans=(ans*(n))%mod;
        //         }
        //     }
        // }
    }
    cout.flush();
    system("pause");
    return 0;
}