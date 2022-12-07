#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=3e5+10;
using namespace std;
ll h[N];
ll b[N];
ll f[N];
struct node{
    ll h,mf,i;
};
stack<node>s;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    f[0]=0;
    f[1]=b[1];
    s.push((node){h[1],f[1],1});
    for(int i=2;i<=n;i++){
        ll ans=-1e16;
        ll mmf=-1e16;
        while(s.size()&&h[i]<s.top().h){
            ans=max(s.top().mf+b[i],ans);
            mmf=max(mmf,s.top().mf);
            s.pop();
        }
        if(s.empty()){
            ans=max(ans,0+b[i]);
            f[i]=ans;
            s.push((node){h[i],max(f[i],mmf),i});
        }
        else{
            f[i]=max(f[s.top().i]+b[i],ans);
            f[i]=max(f[i],f[s.top().i]);
            s.push((node){h[i],max(f[i],mmf),i});
        }
    }
    cout<<f[n];
    //cout.flush();
    //system("pause");
    return 0;
}