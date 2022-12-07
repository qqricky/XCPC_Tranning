#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q,k;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    ll ans=0;
    int l,r;
    for(int i=1;i<=q;i++){
        cin>>l>>r;
        ans=0;
        ans+=(k-(r-l+1));
        ans*=2;
        ans-=(a[l]-1);
        ans-=(k-a[r]);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}