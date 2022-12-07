#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
ll a[N][21];
ll cnt0[N];
ll cnt1[N];
ll sum0[N][21];
ll sum1[N][21];
int cnt=0;
const ll mod=1e9+7;
ll sum[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,q;
    cin>>t;
    while(t--){
        sum[0]=0;
        int n,q;
        cin>>n>>q;
        int tmp;
        for(int i=0;i<=20;i++){
            a[0][i]=0;
            sum0[0][i]=0;
            sum1[0][i]=0;
        }
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt0,0,sizeof(cnt0));
        int pre=0;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(i==1)cnt=tmp;
            tmp^=pre;
            sum[i]=tmp;
            pre=tmp;
            for(int j=0;j<=20;j++){
                a[i][j]=a[i-1][j];
                sum0[i][j]=sum0[i-1][j];
                sum1[i][j]=sum1[i-1][j];
                if((tmp>>j)&1){
                    a[i][j]+=cnt0[j];
                    sum1[i][j]++;
                    cnt1[j]++;
                }
                else{
                    a[i][j]+=cnt1[j];
                    cnt0[j]++;
                    sum0[i][j]++;
                }
            }
        }
        for(int i=1;i<=n;i++)sum[i]+=sum[i-1];
        while(q--){
            int x,y;
            cin>>x>>y;
            bool flag=0;
            x--;
            if(x==0){
                flag=1;
                x=1;
            }
            ll ans=0;
            ll base=1;
            for(int i=0;i<=20;i++,base*=2){
ans=(ans+(a[y][i]-a[x-1][i]-(sum0[y][i]-sum0[x-1][i])*sum1[x-1][i]%mod-(sum1[y][i]-sum1[x-1][i])*sum0[x-1][i]%mod+mod)%mod*base%mod)%mod;
            }
            if(flag){
                //ans=(ans+sum[y]%mod);
                ans=(ans+sum[y])%mod;
            }
            cout<<ans%mod<<'\n';
        }
    }
}//