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
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int ma=0;
        int n;
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            ma=max(ma,x);
            sum+=x;
        }
        if(sum&1){
            cout<<"T\n";
        }
        else{
            if(ma>sum-ma)cout<<"T\n";
            else cout<<"HL\n";
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}