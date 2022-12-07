#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
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
        int n;
        cin>>n;
        int minn=1000;
        for(int i=1;i<=n;i++){cin>>a[i];minn=min(minn,a[i]);}
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]==minn)ans++;
        }
        cout<<n-ans<<endl;
    }
    //system("pause");
    return 0;
}