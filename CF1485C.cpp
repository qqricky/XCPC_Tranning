#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll calc(ll x,ll y)
{
    ll sum=0;
    ll k=sqrt(x);
    if(k<=y)
        sum+=k*(k-1)/2;
    else k=1;
    int pos=0;  
    int pre=0;      
    for(int i=1;i<k;i++){
        sum+=i*(x/i-x/(i+1));
    }
    return sum;
}
int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        ll ans=0;
        if(y==1||x==1){
            cout<<0<<endl;
            continue;
        }
        ll k=sqrt(x);
        if(k<=y)
            ans+=k*(k-1)/2;
        else k=1;
        ll l,r;
        int val=x/(k+1);
        for(int i=k+1;i<=y;i++){
            ll tmp=x/i;
            if(tmp!=val){
                l=i;
                break;
            }
            if(tmp>=i){
                ans+=i-1;
                continue;
            }
            ans+=tmp-1;
            if(x>=tmp*i+tmp)ans++;
            //cout<<x<<' '<<i<<"  : "<<tmp<<endl;
        }
        for(;l<=y;l=r+1){
            r=x/(x/l);
            if(r>=y){
                for(int i=l+1;i<=y;i++){
                    ll tmp=x/i;
                    if(tmp!=val){
                        l=i;
                        break;
                    }
                    if(tmp>=i){
                        ans+=i-1;
                        continue;
                    }
                    ans+=tmp-1;
                    if(x>=tmp*i+tmp)ans++;
                    //cout<<x<<' '<<i<<"  : "<<tmp<<endl;
                }
                break;
            }
            ans+=(r-l+1)*(x/l-1);
            ans+=(l+1)*(x/l)-((x/l)*l+x/l);
        }
        cout<<ans<<"\n";
    }
    //system("pause");
    return 0;
}