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
char mp[1000][1000];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(n<=2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int j=2;j<m;j++){
            int cnt=0;
            for(int i=1;i<=n;i++){
                cnt+=(mp[i][j]=='#');
            }
            if(cnt==0)ans++;
        }
        cout<<ans;
        cout.flush();
        //system("pause");
        return 0;
    }
    if(m<=2){
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int i=2;i<n;i++){
            int cnt=0;
            for(int j=1;j<=m;j++){
                cnt+=(mp[i][j]=='#');
            }
            if(cnt==0)ans++;
        }
        cout<<ans;
        cout.flush();
        //system("pause");
        return 0;
    }
    int ans=0;
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char ch;
            cin>>ch;
            if(ch=='.'){
                if(i==1||i==n)continue;
                if(j==1||j==m)continue;
                ans++;
            }
            else{
                if(i==1||i==n||j==1||j==m){
                    if(i==1&&j==1)continue;
                    if(i==1&&j==m)continue;
                    if(i==n&&j==1)continue;
                    if(i==n&&j==m)continue;
                    flag=0;
                }
            }
        }
    }
    cout<<ans+flag;
    cout.flush();
    //system("pause");
    return 0;
}