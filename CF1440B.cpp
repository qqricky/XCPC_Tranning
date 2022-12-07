#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10; 
using namespace std;
int a[N];
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
        int n,k;
        cin>>n>>k;
        ll ans=0;
        for(int i=1;i<=n*k;i++){
            cin>>a[i];
        }
        int cnt=1;
        int num=(n+1)/2;
        num=n-num+1;
        int tot=0;
        for(int i=n*k;i>=1;i--,cnt++){
            if(tot>=k)break;
            if(cnt%num==0){
                ans+=a[i];
                cnt=0;
                tot++;
            }
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}