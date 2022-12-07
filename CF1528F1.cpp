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
int f[1070];
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=1024;j++){
            if(f[j]<a[i])
                f[j^a[i]]=min(a[i],f[j^a[i]]);
        }
    }
    int cnt=0;
    for(int i=0;i<=1024;i++)if(f[i]!=INF)cnt++;
    cout<<cnt<<'\n';
    for(int i=0;i<=1024;i++){
        if(f[i]!=INF){
            cout<<i<<' ';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}