#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int a[N];
int c[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    int mxx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mxx=max(mxx,a[i]);
    }
    ans+=mxx;
    int mx=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        ans+=c[i];
        mx=max(mx,c[i]);
    }
    cout<<ans-mx;
    cout.flush();
    // system("pause");
    return 0;
}