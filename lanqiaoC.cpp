#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
const ll mod=1e9+7;
ll a[N]={},b[N]={};
int len1,len2,len;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cin>>len1;
    for(int i=len1;i>=1;i--)cin>>a[i];
    cin>>len2;
    for(int i=len2;i>=1;i--)cin>>b[i];
    ll ans=0;
    ll tot=1;
    for(int i=1;i<=len1;i++){
        if(a[i]<b[i]){
            a[i+1]--;
            int k=max(a[i],b[i])+1;
            k=max(k,2);
            ll val=k-(b[i]-a[i]);
            ans=(ans+tot*val%mod)%mod;
            tot=(tot*k)%mod;
        }
        else{
            int k=max(a[i],b[i])+1;
            k=max(k,2);
            //cout<<a[i]-b[i]<<' '<<k<<' '<<tot<<endl;
            ans=(ans+tot*(a[i]-b[i])%mod)%mod;
            tot=(tot*k)%mod;
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}