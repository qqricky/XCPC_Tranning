#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
ll di[280];
ll del[280];
ll y[280];
int f[N]={};
inline ll ceil(ll x, ll b) { return (x + b - 1) / b; }
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    queue<int>q;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>di[i]>>del[i]>>y[i];
    }
    q.push(0);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        int i=f[x]+1;
        ll pos=x;
        for(int k=1;k<=y[i]&&pos<=m;k++){
            pos+=ceil(del[i],1e5);
            if(f[pos]==i)break;
            if(f[pos])continue;
            f[pos]=i;
            q.push(pos);
        }
    }
    //system("pause");
    return 0;
}