#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    a[1]=1;
    for(int i=2;i<=n;i++)a[i]=a[i]=1ll*a[i-1]*i%m;
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum=(sum+1ll*(n-i+1)*a[i]%m*a[n-i+1]%m)%m;
    }
    cout<<sum;
    //system("pause");
    return 0;
}