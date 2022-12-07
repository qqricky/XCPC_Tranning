#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[10070];
vector<int>mp[10070];
int tot=0;
int s[10070];
int l[10070];
int id[10070]={};
int v[10070]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    int x,y,z;
    for(int i=1;i<=m;i++){
        cin>>x>>y>>z;
        mp[x].push_back(i);
        s[i]=y;
        l[i]=z;
        id[y]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(id[i]==0){
            v[i]=1;
            q.push(i);
        }
    }
    while(q.size())
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<mp[x].size();j++){
            id[s[mp[x][j]]]--;
            if(id[s[mp[x][j]]]==0)q.push(s[mp[x][j]]);
            a[s[mp[x][j]]]=min(a[s[mp[x][j]]],a[x]+l[mp[x][j]]);
        }
    }
    ll ans=0;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        ans+=tmp*a[i];
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}