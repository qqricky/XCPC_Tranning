#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
ll s[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>s[i];
        sort(s+1,s+n+1);
        s[n+1]=INF;
        s[0]=-INF;
        int ma=s[n/2];
        int mi=s[n/2];
        ll ans=0;
        int pos2=n/2+1;
        int pos1=n/2-1;
        for(int i=2;i<=n;i++){
            if(s[pos2]-ma<=mi-s[pos1]){
                ans+=s[pos2]-mi;
                ma=s[pos2++];
            }
            else{
                ans+=ma-s[pos1];
                mi=s[pos1--];
            }
        }
        ll cnt=0;
        if(n%2==0){
            ma=s[n/2+1];
            mi=s[n/2+1];
            pos2=n/2+2;
            pos1=n/2;
            for(int i=2;i<=n;i++){
                if(s[pos2]-ma<=mi-s[pos1]){
                    cnt+=s[pos2]-mi;
                    ma=s[pos2++];
                }
                else{
                    cnt+=ma-s[pos1];
                    mi=s[pos1--];
                }
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}