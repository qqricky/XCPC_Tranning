#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int pre[55];
int ne[55];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int pos[55];
    memset(pos,0x3f,sizeof(pos));
    int x;
    vector<int>v;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(i<pos[x]){
            pos[x]=i;
            v.push_back(x);
        }
    }
    for(int i=v.size()-1;i>0;i--){
        pre[v[i]]=v[i-1];
    }
    pre[v[0]]=0;
    for(int i=0;i<v.size()-1;i++){
        ne[v[i]]=v[i+1];
    }
    ne[v[v.size()-1]]=INF;
    ne[0]=v[0];
    for(int i=1;i<=q;i++){
        cin>>x;
        cout<<pos[x]<<' ';
        pos[x]=1;
        int val=pre[x];
        while(val)
        {
            pos[val]++;
            val=pre[val];
        }
        if(ne[x]!=INF){
            ne[pre[x]]=ne[x];
            pre[ne[x]]=pre[x];
        }
        pre[ne[0]]=x;
        pre[x]=0;
        ne[x]=ne[0];
        ne[0]=x;
    }
    //cout.flush();
    //system("pause");
    return 0;
}