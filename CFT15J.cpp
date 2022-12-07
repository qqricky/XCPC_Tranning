#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e3+10; 
using namespace std;
int read()
{
	char ch=getchar();int x=0,f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
bool v[N][N]={};
char mp[N][N];
int f[N][N]={};
int n,m;
int tx,ty;
inline bool ck(int x,int y){
    if(x<1||x>n||y<1||y>m)return 0;
    if(mp[x][y]=='*'&&!(x==tx&&y==ty))return 0;
    if(v[x][y])return 0;
    return 1;
}
map<pair<int,int>,pair<int,int> >tr;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    f[1][1]=0;
    cin>>n>>m;
    deque<pair<int,int> >q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    int t;
    cin>>t;
    int x0,y0,x1,y1;
    int x,y;
    tx=x;
    ty=y;
    vector<pair<int,int> >tmp;
    for(int i=1;i<=t;i++){
        cin>>x0>>y0>>x1>>y1;
        if(mp[x0][y0]=='*'){
            mp[x0][y0]='.';
        }
        if(mp[x1][y1]=='*'){
            tmp.push_back(make_pair(x1,y1));
            tmp.push_back(make_pair(x0,y0));
            continue;
        }
        tr[make_pair(x0,y0)]=make_pair(x1,y1);
    }
    cin>>x>>y;
    for(int i=0;i<tmp.size();i+=2){
        pair<int,int>pr=tmp[i];
        pair<int,int>prr=tmp[i+1];
        if(pr.first==x&&pr.second==y){
            tr[tmp[i+1]]=tmp[i];
        }
    }
    q.push_back(make_pair(1,1));
    while(!q.empty()){
        pair<int,int>u=q.front();
        q.pop_front();
        int xx=u.first;
        int yy=u.second;
        //cout<<xx<<' '<<yy<<endl;
        if(xx==x&&yy==y)break;
        if(tr[make_pair(xx,yy)]!=make_pair(0,0)){
            pair<int,int>kk=tr[make_pair(xx,yy)];
            if(ck(xx,yy)){
                v[kk.first][kk.second]=1;
                f[kk.first][kk.second]=f[xx][yy];
                q.push_front(kk);
            }
            continue;
        }
        bool f1=0,f2=0,f3=0,f4=0;
        if(ck(xx+1,yy)){
            if(tr[make_pair(xx+1,yy)]!=make_pair(0,0)){
                f[xx+1][yy]=f[xx][yy]+1;
                v[xx+1][yy]=1;
                pair<int,int>kk=tr[make_pair(xx+1,yy)];
                if(ck(kk.first,kk.second)){
                    q.push_back(tr[make_pair(xx+1,yy)]);
                    f[kk.first][kk.second]=f[xx][yy]+1;
                    v[kk.first][kk.second]=1;
                }
            }
            else f1=1;
        }
        if(ck(xx-1,yy)){
            if(tr[make_pair(xx-1,yy)]!=make_pair(0,0)){
                f[xx-1][yy]=f[xx][yy]+1;
                v[xx-1][yy]=1;
                pair<int,int>kk=tr[make_pair(xx-1,yy)];
                if(ck(kk.first,kk.second)){
                    q.push_back(tr[make_pair(xx-1,yy)]);
                    f[kk.first][kk.second]=f[xx][yy]+1;
                    v[kk.first][kk.second]=1;
                }
            }
            else f2=1;
        }
        if(ck(xx,yy+1)){
            if(tr[make_pair(xx,yy+1)]!=make_pair(0,0)){
                f[xx][yy+1]=f[xx][yy]+1;
                
                v[xx][yy+1]=1;
                pair<int,int>kk=tr[make_pair(xx,yy+1)];
                if(ck(kk.first,kk.second)){
                    q.push_back(tr[make_pair(xx,yy+1)]);
                    f[kk.first][kk.second]=f[xx][yy]+1;
                    v[kk.first][kk.second]=1;
                }
            }
            else f3=1;
        }
        if(ck(xx,yy-1)){
            if(tr[make_pair(xx,yy-1)]!=make_pair(0,0)){
                f[xx][yy-1]=f[xx][yy]+1;
                v[xx][yy-1]=1;
                pair<int,int>kk=tr[make_pair(xx,yy-1)];
                if(ck(kk.first,kk.second)){
                    q.push_back(tr[make_pair(xx,yy-1)]);
                    f[kk.first][kk.second]=f[xx][yy]+1;
                    v[kk.first][kk.second]=1;
                }
            }
            else f4=1;
        }
        if(f1){
            q.push_back(make_pair(xx+1,yy));
            f[xx+1][yy]=f[xx][yy]+1;
            v[xx+1][yy]=1;
        }
        if(f2){
            q.push_back(make_pair(xx-1,yy));
            f[xx-1][yy]=f[xx][yy]+1;
            v[xx-1][yy]=1;
        }
        if(f3){
            q.push_back(make_pair(xx,yy+1));
            f[xx][yy+1]=f[xx][yy]+1;
            v[xx][yy+1]=1;
        }
        if(f4){
            q.push_back(make_pair(xx,yy-1));
            f[xx][yy-1]=f[xx][yy]+1;
            v[xx][yy-1]=1;
        }
    }
    if(f[x][y]==0&&(x+y)!=2)cout<<"No solution";
    else cout<<f[x][y];
    //cout<<endl;
    //system("pause");
    return 0;
}