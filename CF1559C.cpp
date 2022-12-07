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
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    a[0]=1;
    while(t--)
    {
        int n;
        cin>>n;
        int pos=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1&&a[i-1]==0){
                pos=i;
            }
        }
        if(!pos&&a[1]==1){
            cout<<n+1<<' ';
            for(int i=1;i<=n;i++)cout<<i<<' ';
            cout<<'\n';
            continue;
        }
        if(!pos&&a[n]==0){
            for(int i=1;i<=n;i++)cout<<i<<' ';
            cout<<n+1<<' ';
            cout<<'\n';
            continue;
        }
        if(!pos)cout<<-1<<'\n';
        else{
            for(int i=1;i<pos;i++)cout<<i<<' ';
            cout<<n+1<<' ';
            for(int i=pos;i<=n;i++)cout<<i<<' ';
            cout<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}