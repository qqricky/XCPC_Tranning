#include <bits/stdc++.h>
using namespace std;
#define ll long long
int k[300002]={};
ll c[300002]={};
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>k[i];
        for(int i=1;i<=m;i++)cin>>c[i];
        sort(k+1,k+n+1,greater<int>{});
        ll ans=0;
        ll val=1;
        for(int i=1;i<=n;i++){
            if(c[k[i]]<c[val]){
                ans+=c[k[i]];
                continue;
            }
            if(val<=m){
                ans+=c[val++];
            }
            else{
                ans+=c[k[i]];
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}