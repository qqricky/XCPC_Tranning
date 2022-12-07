#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
ll a[150];
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
        int n;
        ll u,v;
        cin>>n>>u>>v;
        ll cost=min(2*v,u+v);
        a[0]=-2;
        cin>>a[1];
        int f=0;
        for(int i=2;i<=n;i++){
            cin>>a[i];
        }
        ll ans=0;
        int flag=1;
        f=0;
        int pos;
        if(0){
            if(a[2]==0){
                ans+=min(2*v,u+v);
            }
            else if(a[2]==1){
                for(int i=2;i<=n;i++){
                if(abs(a[i]-a[i-1])==1)f=1;
                if(abs(a[i]-a[i-1])>1){
                    flag=0;
                    break;
                }
            if(a[i]==0)break;
            pos=i;
        }
            }
        }
        for(int i=2;i<=n;i++){
            if(abs(a[i]-a[i-1])==1)f=1;
            if(abs(a[i]-a[i-1])>1){
                flag=0;
                break;
            }
            if(a[i]==0)break;
            pos=i;
        }
        if(flag&&f){
            ans+=min(u,v);
            if(pos==n){
                cout<<ans<<endl;
                continue;
            }    
        }
        else if(flag){
            ans+=min(u+v,2*v);
            cout<<ans<<endl;
            continue;
        }
        flag=1;
        f=0;
        for(int i=n-1;i>=1;i--){
            if(abs(a[i+1]-a[i])>1){
                flag=0;
                break;
            }
            if(a[i]==100001)break;
        }
        if(flag)ans+=min(u,v);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}