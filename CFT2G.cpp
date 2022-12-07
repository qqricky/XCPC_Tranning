#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll l,g;
    cin>>l>>g;
    ll ans=0;
    for(int i=1;i<=g;i++){
        ll x,y;
        cin>>x>>y;
        if(y){
            ans=max(ans,l-x);
        }
        else{
            ans=max(ans,x);
        }
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}