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
int mp[8][8]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mp[x][y]=mp[y][x]=1;
    }
    if(n<=6){
        cout<<m;
        return 0;
    }
    int cnt=INF;
    for(int i=1;i<=7;i++){
        for(int j=i+1;j<=7;j++){
            int cntt=0;
            for(int k=1;k<=7;k++){
                if(k==i||k==j)continue;
                if(mp[i][k]&&mp[j][k])cntt++;
            }
            cnt=min(cnt,cntt);
        }
    }
    cout<<m-cnt;
    cout.flush();
    //system("pause");
    return 0;
}