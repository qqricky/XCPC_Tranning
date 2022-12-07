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
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<'\n';
        }
        else{
            int cnt=0;
            int aa=a,bb=b;
            while(b!=(a|b)){
                // cout<<"to ";
                // cout<<b<<' '<<(a|b)<<endl;
                b++;
                cnt++;
            }
            if(a!=b)cnt++;
            int cnt2=0;
            while(bb!=(aa|bb)){
                // cout<<"to ";
                // cout<<b<<' '<<(a|b)<<endl;
                aa++;
                cnt2++;
            }
            if(aa!=bb)cnt2++;
            cout<<min(cnt,cnt2)<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}