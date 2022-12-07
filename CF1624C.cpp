#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=200;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int a[N];
bool vis[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            while(a[i]>n||vis[a[i]]){
                a[i]/=2;
            }
            if(a[i]!=0){
                vis[a[i]]=1;
            }
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                flag=0;
                break;
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    system("pause");
    return 0;
}