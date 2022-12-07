#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
ll f[N];
const ll mod=1e9+7;
unordered_map<int,ll>num;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    f[1]=1;
    for(int i=1;i<=n;i++){
        vector<int>v;
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                v.push_back(j);
                while(a[i]%j==0){
                    a[i]/=j;
                }
            }
        }
        if(a[i]>1)v.push_back(a[i]);
        int len=v.size();
        for(int j=1;j<(1<<len);j++){
            int cnt=0;
            ll acu=1;
            for(int k=0;k<len;k++){
                if((j>>k)&1){
                    cnt++;
                    acu*=v[k];
                }
            }
            if(cnt&1){
                f[i]=(f[i]+num[acu])%mod;
            }else{
                f[i]=(f[i]-num[acu]+mod)%mod;
            }
        }
        for(int j=1;j<(1<<len);j++){
            int cnt=0;
            ll acu=1;
            for(int k=0;k<len;k++){
                if((j>>k)&1){
                    cnt++;
                    acu*=v[k];
                }
            }
            num[acu]=(num[acu]+f[i])%mod;
        }
    }
    cout<<f[n];
    cout.flush();
    // system("pause");
    return 0;
}