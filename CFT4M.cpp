#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
int a[N];
int f[N];
int x[N];
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
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        queue<int>q;
        f[1]=0;
        q.push(1);
        int k;
        int ans=0;
        for(int i=2;i<=n;i++){
            k=q.front();
            if(a[i]>a[i-1]){
                f[a[i]]=f[k]+1;
                ans=max(ans,f[a[i]]);
                q.push(a[i]);
                continue;
            }
            q.pop();
            k=q.front();
            f[a[i]]=f[k]+1;
            q.push(a[i]);
            ans=max(ans,f[a[i]]);
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}