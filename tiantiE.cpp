#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+10;
const ll mod=1e9+7;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a; 
}
ll pow_Q(ll a,ll b)
{
    ll ans=1;
    ll base=a;
    while(b)
    {
        if(b&1){
            ans=(ans*base)%mod;
        }
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
map<ll,int>mp;
struct node
{
    ll val;
    int pos;
    int num=0;
    vector<int>v;
}t[N];
vector<int>a[N];
bool cmp(node x,node y)
{
    if(x.num!=y.num)
    return x.num>y.num;
    else
    return x.v<y.v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int poss=1;
    int tmp;
    for(int i=1;i<=n;i++){
        ll val=0;
        for(int j=1;j<=m;j++){
            cin>>tmp;
            a[i].push_back(tmp);
            val=(val*131+tmp)%mod;
        }
        if(!mp[val]){
            mp[val]=i;
            t[i].val=val;
            t[i].pos=i;
            t[i].num=1;
            t[i].v=a[i];
        }
        else{
            t[mp[val]].num++;
        }
    }
    sort(t+1,t+n+1,cmp);
    while(t[poss].num)poss++;
    cout<<poss-1<<endl;
    for(int i=1;i<=n;i++){
        if(t[i].num==0)break;
        cout<<t[i].num<<' ';
        for(int j=0;j<t[i].v.size()-1;j++){
            cout<<t[i].v[j]<<' ';
        }
        cout<<t[i].v[t[i].v.size()-1]<<"\n";
    }
    //system("pause");
    return 0;
}