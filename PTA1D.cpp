#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int isprime(ll x)
{
    if(x==1)return 0;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0)return 0;
    }
    return 1;
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
    while(n--)
    {
        ll x;
        cin>>x;
        if(isprime(x))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}