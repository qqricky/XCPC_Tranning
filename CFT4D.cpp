#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int gcd(int x,int y)
{
    return y ? gcd(y,x%y) : x;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int a,b;
    cin>>t>>a>>b;
    for(int i=1;1;i++){
        if(i&1){
            t-=gcd(b,t);
        }
        else{
            t-=gcd(a,t);
        }
        if(t<0){
            if(i&1)cout<<1;
            else cout<<0;
            break;
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}