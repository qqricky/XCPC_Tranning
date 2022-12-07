#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
char mp[1070][1070];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=4*n+5;i++){
        for(int j=1;j<=13*n+19;j++){
            mp[i][j]='.';
        }
    }
    for(int i=1;i<=4*n+5;i++){
        mp[i][1]='*';
        mp[i][13*n+19]='*';
    }
    for(int j=1;j<=13*n+19;j++){
        mp[1][j]='*';
        mp[4*n+5][j]='*';
    }
    int m=n+3;
    for(int i=n+2,j=m;i<=n+1+2*n+3;i++,j++){
        mp[i][m]='@';
        mp[i][m+2*n+2]='@';
        mp[i][j]='@';
    }
    m=1+n+1+2*n+3+n+1+1;
    for(int i=n+2;i<=n+1+2*n+3;i++){
        mp[i][m]='@';
    }
    for(int j=m;j<=m+2*n+2;j++){
        mp[n+2][j]='@';
        mp[n+1+n+2][j]='@';
    }
    m+=2*n+3;
    m+=n+1;
    for(int i=n+2;i<=n+1+2*n+3;i++){
        mp[i][m]='@';
    }
    for(int j=m;j<=m+2*n+2;j++){
        mp[n+1+2*n+3][j]='@';
    }
    m+=2*n+3;
    m+=n+1;
    for(int j=m;j<=m+2*n+2;j++){
        mp[n+2][j]='@';
        mp[n+2+n+1][j]='@';
        mp[n+1+2*n+3][j]='@';
    }
    for(int i=n+2;i<=n+2+n+1;i++){
        mp[i][m]='@';
    }
    for(int i=n+2+n+2;i<=n+1+2*n+3;i++){
        mp[i][m+2*n+2]='@';
    }
    for(int i=1;i<=4*n+5;i++){
        for(int j=1;j<=13*n+19;j++){
            cout<<mp[i][j];
        }
        cout<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}