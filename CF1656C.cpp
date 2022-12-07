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
    while(t--){
        int n;
        cin>>n;
        bool f0=0,f1=0,f2=0;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a[i]=x;
            if(x==0)f0=1;
            else if(x==1)f1=1;
            else if(x==2)f2=1;
        }
        sort(a+1,a+n+1);
        bool fl=0;
        for(int i=1;i<n;i++){
            if(a[i]+1==a[i+1]){
                fl=1;
                break;
            }
        }
        if((f0&&f1)||(f1&&f2)){
            cout<<"NO\n";
        }
        else if(f1&&fl){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}