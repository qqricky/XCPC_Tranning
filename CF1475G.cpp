#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10;
using namespace std;
int a[N];
int d[N];
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
        int ans=0;
        cin>>n;
        memset(d,0,sizeof(d));
        for(int i=1;i<=n;i++){cin>>a[i];}
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            int k=a[i];
            for(int i=1;i*i<=k;i++){
                if(k%i==0){
                    d[k]=max(d[k],max(d[i],d[k/i])+1);
                }
            }
            ans=max(ans,d[k]);
        }
        cout<<n-ans<<"\n";
    }
    //system("pause");
    return 0;
}