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
bool ck(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return 1;
    }
    return 0;
}
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
        int sum=0;
        int fl=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            if(a[i]&1)fl=i;
        }
        if(sum&1 && !ck(sum)){
            cout<<n-1<<endl;
            for(int i=1;i<=n;i++){
                if(i==fl)continue;
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<n<<endl;
            for(int i=1;i<=n;i++)cout<<i<<' ';
            cout<<endl;
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}