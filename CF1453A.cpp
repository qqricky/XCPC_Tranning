#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;

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
        int n,m,x;
        cin>>n>>m;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            cin>>x;
            mp[x]++;
        }
        int ans=n;
        for(int i=1;i<=m;i++){
            cin>>x;
            if(!mp[x])ans++;
        }
        cout<<n+m-ans<<endl;
    }
    //system("pause");
    return 0;
}