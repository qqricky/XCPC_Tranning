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
int x[N],y[N];
int pos[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        int ans=0;
        for(int j=1;j*j<=x[i];j++){
            if(x[i]%j==0){
                if(pos[j]<i-y[i]){
                    ans++;
                }
                pos[j]=i;
                if(pos[x[i]/j]<i-y[i]){
                    ans++;
                }
                pos[x[i]/j]=i;
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}