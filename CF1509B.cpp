#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e3+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
char mp[N][N];
int v[N][N]={};
int cnt=0;
void solve(int x,int y){
    bool flag=0;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i*j==1)continue;
            if(mp[x+i][y+j]=='.'){
                flag=1;
                break;
            }
        }
    }
    if(flag)return;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(i*j==1)continue;
            cnt-=(!v[x+i][y+j]);
            v[x+i][y+j]=1;
        }
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
            cnt+=(mp[i][j]=='#');
        }
    }
    for(int i=1;i+2<=n;i++){
        for(int j=1;j+2<=m;j++){
            solve(i,j);
        }
    }
    if(cnt)cout<<"NO";
    else cout<<"YES";
    cout.flush();
    //system("pause");
    return 0;
}