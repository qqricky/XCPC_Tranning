#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll a[505][505];
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll lm=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            lm=lcm(a[i][j],lm);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if((i+j)&1){
                cout<<lm<<' ';
            }
            else{
                cout<<lm+a[i][j]*a[i][j]*a[i][j]*a[i][j]<<' ';
            }
        }
        cout<<"\n";
    }
    //system("pause");
    return 0;
}