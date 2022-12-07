#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
vector<int>mp1[N];
vector<int>mp2[N];
int v1[N]={};
int v2[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,s;
    cin>>n>>m>>s;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        mp1[x].push_back(y);
        mp2[y].push_back(x);
    }
    queue<int>q;
    q.push(s);
    int cnt=0;
    while(q.size())
    {
        int x=q.front();
        while(v1[x]){
            q.pop();
            if(q.empty())goto paris;
            x=q.front();
        }
        q.pop();
        cnt++;
        v1[x]=1;
        for(int j=0;j<mp1[x].size();j++){
            if(!v1[mp1[x][j]]){
                q.push(mp1[x][j]);
            }
        }
    }
    paris:;
    while(q.size())q.pop();
    q.push(s);
    while(q.size())
    {
        int x=q.front();
        while(v2[x]){
            q.pop();
            if(q.empty())goto paris2;
            x=q.front();
        }
        q.pop();
        v2[x]=1;
        cnt++;
        for(int j=0;j<mp2[x].size();j++){
            if(!v2[mp2[x][j]]){
                q.push(mp2[x][j]);
            }
        }
    }
    paris2:;
    cout<<2*n-cnt;
    //system("pause");
    return 0;
}