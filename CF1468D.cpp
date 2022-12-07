#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll ma[200002]={};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,n,m;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        for(int i=1;i<=m;i++)cin>>ma[i];
        sort(ma+1,ma+m+1,greater<ll>());
        ll k=abs(b-a)-1;
        if(a<b)b=b-1;
        else b=n-b;
        b--;
        int ans=0;
        for(int i=1;i<=m;i++){
            if(ma[i]<=b-ans&&k>0){
                ans++;
                k--;
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}