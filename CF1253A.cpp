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
int a[N],b[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    a[0]=b[0]=0;
    while(t--){
        int n;
        cin>>n;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for(int i=n;i>=1;i--){
            if(a[i]>b[i])flag=0;
            a[i]-=a[i-1];
            b[i]-=b[i-1];
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=b[i]){
                if(!cnt){
                    cnt=b[i]-a[i];
                }
                else if(cnt==-1){
                    flag=0;
                    break;
                }
                else{
                    if(cnt!=a[i]-b[i]){
                        flag=0;
                        break;
                    }
                    cnt=-1;
                }
            }
        }
        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}