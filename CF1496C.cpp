#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
ll h[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>h[i];
        int flag=1;
        ll l=h[1]+1;
        ll r=h[1]+k;
        for(int i=2;i<=n-1;i++){
            if(h[i]+2*k-1<l||h[i]>=r){
                flag=0;
                break;
            }
            l=max(l-k+1,h[i]+1);
            r=min(r+k-1,2*k-1+h[i]);
        }
        if(l>h[n]+k||r<=h[n])flag=0;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}