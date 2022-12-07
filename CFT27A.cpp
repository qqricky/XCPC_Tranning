#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int mp[200][200]={};
int x,y,z;
bool ck(int i,int j){
    if(mp[i][j]!=x)return 0;
    if(mp[i-1][j]==y&&mp[i][j+1]==z)return 1;
    if(mp[i][j+1]==y&&mp[i+1][j]==z)return 1;
    if(mp[i+1][j]==y&&mp[i][j-1]==z)return 1;
    if(mp[i][j-1]==y&&mp[i-1][j]==z)return 1;
    return 0;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    cin>>x>>y>>z;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ck(i,j)){
                cout<<i-1<<' '<<j-1<<'\n';
            }
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}