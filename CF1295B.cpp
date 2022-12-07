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
int pre[N];
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
        int n,x;
        int ans=0;
        cin>>n>>x;
        string str;
        cin>>str;
        str=' '+str;
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1];
            if(str[i]=='0')pre[i]++;
            else pre[i]--;
            if(pre[i]==x)ans++;
        }
        if(x==0)ans++;
        if(pre[n]==0){
            if(ans>0)cout<<-1<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        if(pre[n]>0){
            for(int i=1;i<=n;i++){
                if(pre[i]<x&&(x-pre[i])%pre[n]==0){
                    ans++;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(pre[i]>x&&(x-pre[i])%pre[n]==0){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}