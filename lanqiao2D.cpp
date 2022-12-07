#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
ll powq(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=(res*a);
        a*=a;
        b>>=1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    string str;
    cin>>str>>a>>b;
    ll ans=0;
    int mx=str.size();
    for(int j=0;j<(1ll<<mx);j++){
        int x=a,y=b;
        ll res=0;
        for(int i=0;i<mx;i++){
            if((j>>i)&1){
                int to='9'-str[i];
                to=min(to,x);
                x-=to;
                res+=(str[i]-'0'+to)*powq(10,mx-i-1);
            }else{
                int to=str[i]-'0'+1;
                if(y>=to){
                    y-=to;
                    res+=9*powq(10,mx-i-1);
                }else{
                    res+=(str[i]-'0')*powq(10,mx-i-1);
                }
            }
        }
        ans=max(ans,res);
    }
    cout<<ans;
    // cout.flush();
    // system("pause");
    return 0;
}