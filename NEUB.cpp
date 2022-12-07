#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
int a[N]={};
int n,k;
int check(ll dis)
{
    int cnt=0;
    ll now=a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-now>dis){
            cnt++;
            now=now+dis;
            i--;
            continue;
        }
        now=a[i];
    }
    if(cnt>k)return 0;
    else return 1;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1;
    ll r=a[n]-a[1];
    ll mid;
    ll ans=a[n]-a[1];
    while(l<r)
    {
        mid=(l+r)>>1;
        cout<<mid<<endl;
        if(check(mid)){
            ans=mid;
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}