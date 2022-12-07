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
    ll val;
    while(t--){
        cin>>val;
        ll tmp=val+1;
        if(tmp-(tmp&-tmp)==0){
            ll pos=0;
            for(int i=2;i*i<=val;i++){
                if(val%i==0){
                    pos=i;
                    break;
                }
            }
            if(pos==0){
                pos=val;
            }
            cout<<val/pos<<'\n';
            continue;
        }
        ll base=1;
        while(val>=base){
            base<<=1;
        }
        base--;
        cout<<base<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}