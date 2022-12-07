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
int mp[3070][3070];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    char ch;
    int cntt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ch;
            if(ch=='*'){
                mp[i][j]=1;
            }
            else{
                cntt++;
                mp[i][j]=0;
            }
        }
    }
    if(k==1){
        cout<<cntt<<endl;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(mp[i][j]){
                cnt=0;
                continue;
            }
            cnt++;
            if(cnt>=k)ans++;
        }
    }
    for(int j=1;j<=m;j++){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(mp[i][j]){
                cnt=0;
                continue;
            }
            cnt++;
            if(cnt>=k)ans++;
        }
    }
    cout<<ans<<endl;
    cout.flush();
    //system("pause");
    return 0;
}