#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e3+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int mp[N][N]={};
ll g0,x,y,z;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    ll g0,x,y,z;
    cin>>g0>>x>>y>>z;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            mp[i][j]=g0;
            g0=(g0*x+y)%z;
        }
    }
    for(int i=1;i<=n;i++){
        deque<int>q;
        for(int j=1;j<=b;j++){
            while(!q.empty()&&mp[i][j]<=q.back()){
                q.pop_back();
            }
            q.push_back(mp[i][j]);
        }
        for(int j=1;j+b-1<=m;j++){
            int tmp=mp[i][j];
            mp[i][j]=q.front();
            if(tmp==q.front())q.pop_front();
            while(!q.empty()&&mp[i][j+b]<=q.back()){
                q.pop_back();
            }
            q.push_back(mp[i][j+b]);
        }
    }
    for(int i=1;i<=m;i++){
        deque<int>q;
        for(int j=1;j<=a;j++){
            while(!q.empty()&&mp[j][i]<=q.back()){
                q.pop_back();
            }
            q.push_back(mp[j][i]);
        }
        for(int j=1;j+a-1<=n;j++){
            int tmp=mp[j][i];
            mp[j][i]=q.front();
            if(tmp==q.front())q.pop_front();
            while(!q.empty()&&mp[j+a][i]<=q.back()){
                q.pop_back();
            }
            q.push_back(mp[j+a][i]);
        }
    }
    ll ans=0;
    for(int i=1;i+a-1<=n;i++){
        for(int j=1;j+b-1<=m;j++){
            ans+=mp[i][j];
        }
    }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}