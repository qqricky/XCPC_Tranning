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
    int n;
    cin>>n;
    int a[3];
    for(int i=1;i<=n;i++){
        cin>>a[1]>>a[2];
        sort(a+1,a+3);
        int ans=max(2*a[1],a[2]);
        cout<<(ll)ans*ans<<endl;
    }
    //system("pause");
    return 0;
}