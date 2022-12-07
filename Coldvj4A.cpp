#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int id[105]={};
int od[105]={};
vector<int>mp[105];
vector<int>mpp[105];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int v[105]={};
    int gg=0;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        if(!v[x]){
            v[x]=1;
            gg++;
        }
        if(!v[y]){
            v[y]=1;
            gg++;
        }
        mp[x].push_back(y);
        mpp[y].push_back(x);
        id[y]++;
        od[x]++;
    }
    if(gg<n){
        cout<<0;
        return 0;
    }
    int cnt=0;
    int pos=0;
    int cntt=0;
    int poss=0;
    int tmp=0;
    for(int i=1;i<=n;i++){
        if(id[i]+od[i]==n-1)tmp=i;
        if(id[i]==0){
            cnt++;
            pos=i;
        }
        if(od[i]==0){
            cntt++;
            poss=i;
        }
    }
    int ans=0;
    queue<int>q;
    if(cntt==1){
        q.push(poss);
        while(q.size()){
            int k=q.front();
            q.pop();
            ans++;
            int num=0;
            int val=0;
            for(int j=0;j<mpp[k].size();j++){
                od[mpp[k][j]]--;
                if(od[mpp[k][j]]==0){num++;val=mpp[k][j];}
            }
            if(num==1){
                q.push(val);
            }
        }
    }
    if(cnt==1){
        q.push(pos);
        while(q.size()){
            int k=q.front();
            q.pop();
            ans++;
            int num=0;
            int val=0;
            for(int j=0;j<mp[k].size();j++){
                id[mp[k][j]]--;
                if(id[mp[k][j]]==0){num++;val=mp[k][j];}
            }
            if(num==1){
                q.push(val);
            }
        }
    }
    cout<<ans;
    //system("pause");
    return 0;
}