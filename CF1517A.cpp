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
    int n,m;
    int t;
    cin>>t;
    vector<int>v;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int tmp;
                cin>>tmp;
                v.push_back(tmp);
            }
        }
        sort(v.begin(),v.end());
        ll ans=0;
        for(int i=0;i<n;i++)ans+=v[i];
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}