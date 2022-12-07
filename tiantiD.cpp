#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+10;
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
vector<int>mp[N];
vector<int>f[N];
int ind[N]={};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int k;
    for(int i=0;i<n;i++){
        cin>>k;
        int tmp;
        for(int j=1;j<=k;j++){
            cin>>tmp;
            mp[i].push_back(tmp);
            ind[tmp]=1;
        }
    }
    int pos;
    for(int i=0;i<n;i++)if(ind[i]==0){
        pos=i;
        break;
    }
    queue<int>q;
    q.push(pos);
    int ms=0;
    f[pos].push_back(pos);
    vector<int>ans;
    while(q.size())
    {
        int k=q.front();
        q.pop();
        for(int j=0;j<mp[k].size();j++){
            int t=mp[k][j];
            f[t]=f[k];
            f[t].push_back(t);
            q.push(t);
        }
        if(mp[k].size()==0){
            if(ans.size()<f[k].size()){
                ans=f[k];
            }
            else if(ans.size()==f[k].size()){
                if(ans>f[k]){
                    ans=f[k];
                }
            }
        }
    }
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<' ';
    cout<<ans[ans.size()-1];
    //system("pause");
    return 0;
}