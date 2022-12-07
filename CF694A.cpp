#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long
ll a[100002]={};
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        ll mi=0;
        ll ma=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ma+=ceil((double)a[i]/x);
            mi+=a[i];
        }
        ll ans=ceil((double)mi/x);
        cout<<ans<<' '<<ma<<endl;
    }
    //system("pause");
    return 0;
}