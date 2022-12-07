#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll d[510]={};
void add(ll x)
{
    for(int i=50;i>=0;i--){
        if(x&(1ll<<i)){
            if(d[i]){
                x^=d[i];
            }
            else{
                d[i]=x;
                break;
            }
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        add(tmp);
    }
    ll ans=0;
    for(int i=50;i>=0;i--){
        if(d[i]){
            ans=max(ans,ans^d[i]);
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}