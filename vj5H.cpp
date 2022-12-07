#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=6e6+10; 
using namespace std;
string str;
ll Mod=1e9+7;
int dp[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>str;
    ll ans , i , l , p , q , temp ;
        memset(dp,0,sizeof(dp)) ;
        l=str.length();
        dp[0] = 1 ;
        ans = 1 ;
        p = q = str[0] ;
        temp = 1 ;
        for(i = 1 ; i < l ; i++) {
            p = (p*131+str[i]) % Mod ;
            temp = (temp*131) % Mod ;
            q = (str[i]*temp + q) % Mod ;
            if( p == q ) {
                dp[i] = dp[(i-1)/2] + 1 ;
                ans += dp[i] ;
            }
        }
    cout<<ans<<endl;
    system("pause");
    return 0;
}