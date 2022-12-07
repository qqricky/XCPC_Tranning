#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    ll a,b,c;
    cin>>a>>b>>c;
    if(a>(b+c)){
        cout<<"YES"<<endl;
        if(b+c==0)cout<<0;
        else cout<<2*(b+c)+1;
    }
    else{
        cout<<"NO";
    }
    cout.flush();
    system("pause");
    return 0;
}