#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[1070],b[1070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int pos=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        while(cnt<a[i]){
            cnt+=b[pos];
            pos++;
        }
        ans+=cnt-a[i];
        cnt=0;
    }
    for(int j=pos;j<=m;j++)ans+=b[j];
    cout<<ans<<endl;
    //system("pause");
    return 0;
}