#include <bits/stdc++.h>
#define ll long long
const int N=1e3+10; 
using namespace std;
int w[N],v[N];
ll f[N];
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
        memset(f,0,sizeof(f));
        int n,vi;
        cin>>n>>vi;
        for(int i=1;i<=n;i++)cin>>w[i];
        for(int i=1;i<=n;i++)cin>>v[i];
        for(int i=1;i<=n;i++){
            for(int j=vi;j>=v[i];j--){
                f[j]=max(f[j],f[j-v[i]]+w[i]);
            }
        }
        cout<<f[vi]<<endl;
    }
    //system("pause");
    return 0;
}