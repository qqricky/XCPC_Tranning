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
char mp[500][500];
inline bool ck(int x,int y,int r){
    if(mp[x][y]=='*'&&mp[x-r][y]=='*'&&mp[x+r][y]=='*'){
        if(mp[x][y-r]=='*'&&mp[x][y+r]=='*'){
            return 1;
        }
    }
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    bool flag=0;
    for(int r=1;r*2+1<=min(n,m);r++){
        for(int i=r+1;i+r<=n;i++){
            for(int j=r+1;j+r<=m;j++){
                if(ck(i,j,r)){
                    cnt++;
                }
                if(cnt==k){
                    flag=1;
                    cout<<i<<' '<<j<<'\n';
                    cout<<i-r<<' '<<j<<'\n';
                    cout<<i+r<<' '<<j<<'\n';
                    cout<<i<<' '<<j-r<<'\n';
                    cout<<i<<' '<<j+r<<'\n';
                    break;    
                }
            }
            if(flag)break;
        }
        if(flag)break;
    }
    if(!flag){
        cout<<-1;
    }
    cout.flush();
    //system("pause");
    return 0;
}