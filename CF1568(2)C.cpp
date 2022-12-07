#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e6+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<int>mp[N];
vector<int>v[N];
int pos;
int di[]={0,1,0,-1};
int n,m;
bool ck(int x,int y){
    if(x>n||x<1||y>m||y<1)return false;
    if(v[x][y]||mp[x][y])return false;
    return true;
}
void dfs(int x,int y){

    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(ck(x+di[i],y+di[j])){
                dfs(x+di[i],y+di[j]);
            }
        }
    }
}
int dis[N]={};
int diss[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp[i].push_back(0);
        v[i].push_back(0);
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='X'){
                if(i<=n)
                mp[i].push_back(1);
                v[i].push_back(1);
            }
            else{    
                mp[i].push_back(0);
                v[i].push_back(0);
            }
        }
        mp[i].push_back(1);
    }
    for(int j=1;j<=m;j++){
        mp[0].push_back(0);
        mp[n+1].push_back(1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!v[i][j]){
                queue<pair<int,int> >q;
                q.push(make_pair(i,j));
                int l=j,r=j;
                int flag=1;
                v[i][j]=1;
                while(!q.empty()){
                    pair<int,int>pr=q.front();
                    q.pop();
                    int x=pr.first;
                    int y=pr.second;
                    cout<<x<<' '<<y<<endl;
                    if(y==1||x==1)flag=0;
                    l=min(l,y);
                    r=max(r,y);
                    if(ck(x+1,y)){
                        q.push(make_pair(x+1,y));
                        v[x+1][y]=1;
                    }
                    if(ck(x,y+1)){
                        q.push(make_pair(x,y+1));
                        v[x][y+1]=1;
                    }
                    if(ck(x-1,y)){
                        q.push(make_pair(x-1,y));
                        v[x-1][y]=1;
                    }   
                    if(ck(x,y-1)){
                        q.push(make_pair(x,y-1));
                        v[x][y-1]=1;
                    }
                }
                if(flag){
                    //cout<<l<<' '<<r<<endl;
                    //cout<<"HFKJSDHKJFHJKSD"<<endl;
                    dis[l-1]+=1;
                    dis[r+2]-=1;
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int i=1;i<=m;i++){
        dis[i]+=dis[i-1];
        cout<<dis[i]<<' ';
        diss[i]=diss[i-1]+dis[i];
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(diss[y]-diss[x-1]==0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    system("pause");
    return 0;
}