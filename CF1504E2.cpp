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
ll maxx[N]={};
ll f[N];
bool operator < (const ll &y , const node &x)
{
    return y<x.a;
}
bool cmp(node x,node y)
{
    if(x.a==y.a)return x.c<y.c;
    return x.a<y.a;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    memset(f,0x3f,sizeof(f));
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].c;
        sum+=arr[i].c;
    }
    sort(arr+1,arr+n+1,cmp);
    for(int i=1;i<=n;i++){
        maxx[i]=max(maxx[i-1],arr[i].a+arr[i].c);
    }
    arr[n+1].a=1e16;
    ll pos=1;
    //if(n==99999)cout<<sum<<endl;
    while(arr[pos+1].a==arr[pos].a)pos++;
    while(pos<n)
    {
        ll tmp=maxx[pos];
        ll k=upper_bound(arr+pos,arr+n+1,tmp)-arr-1;
        //cout<<k<<endl;
        if(k==pos){
            //cout<<sum<<endl;
            sum+=(arr[pos+1].a-tmp);
            pos++;
        }
        else{
            pos=k;
        }
    }
    cout<<sum<<endl;
    //system("pause");
    return 0;
}