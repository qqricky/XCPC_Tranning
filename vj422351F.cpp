#include <bits/stdc++.h>
#define ll long long
const int N=2e5+10; 
using namespace std;
int n,m,d;
int cnt=0;
int x1,x2,y1,y2;
int v[N]={};
vector<int>mp[N];
vector<int>f[N];
int ck(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)return 1;
    else return 0;
}
void mst(int x,int y,int k)
{
    mp[x][y]=cnt;
    if(k==0)return;
    if(ck(x+1,y)&&mp[x+1][y]!=cnt)mst(x+1,y,k-1);
    if(ck(x,y+1)&&mp[x][y+1]!=cnt)mst(x,y+1,k-1);
    if(ck(x-1,y)&&mp[x-1][y]!=cnt)mst(x-1,y,k-1);
    if(ck(x,y-1)&&mp[x][y-1]!=cnt)mst(x,y-1,k-1);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n>>d;
    char ch;
    if(d>=n+m){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        mp[i].push_back(0);
        for(int j=1;j<=n;j++){
            cin>>ch;
            if(ch=='M'){
                cnt++;
                mp[i].push_back(cnt);
            }
            else if(ch=='S'){
                x1=i;
                y1=j;
                mp[i].push_back(0);
            }
            else if(ch=='F'){
                x2=i;
                y2=j;
                mp[i].push_back(0);
            }
            else mp[i].push_back(0);
        }
    }
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]&&!v[mp[i][j]]){
                cnt++;
                v[mp[i][j]]=1;
                mst(i,j,d);
            }
        }
    }
    queue<pair<int,int> >q;
    q.push(make_pair(x1,y1));
    int step=1;
    while(!q.empty())
    {

    }
    //system("pause");
    return 0;
}