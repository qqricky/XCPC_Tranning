#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
struct node
{
    ll a;
    ll c;
}arr[N];
bool cmp(node x,node y)
{
    return x.a>y.a;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].c;
        sum+=arr[i].c;
    }
    sort(arr+2,arr+n+1,cmp);
    sum-=(arr[n].c+arr[1].c);
    ll ans=sum+max(arr[1].c,arr[2].a-arr[1].a)+max(arr[n].c,arr[1].a-arr[n].a);
    for(int i=3;i<=n;i++){
        ans=min(ans,sum-arr[i-1].c+max(arr[2].a-arr[n].a,arr[n].c)+max(arr[1].a-arr[i-1].a,arr[i-1].c)+max(arr[1].c,arr[i].a-arr[1].a));
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}