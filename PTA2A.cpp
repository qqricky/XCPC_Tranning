#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
vector<int>mp[N];
int f[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int od;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        if(tmp==-1){
            f[i]=1;
            od=i;
            continue;
        }
        mp[tmp].push_back(i);
    }
    queue<int>q;
    q.push(od);
    int minn=0;
    while(q.size())
    {
        int k=q.front();
        q.pop();
        for(int i=0;i<mp[k].size();i++){
            q.push(mp[k][i]);
            f[mp[k][i]]=f[k]+1;
            minn=max(minn,f[mp[k][i]]);
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(f[i]==minn){
            ans.push_back(i);
        }
    }
    cout<<minn<<endl;
    for(int i=0;i<ans.size()-1;i++)cout<<ans[i]<<' ';
    cout<<ans[ans.size()-1];
    //system("pause");
    return 0;
}