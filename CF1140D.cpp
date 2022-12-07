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
    int n;
    cin>>n;
    vector<int>v;
    for(int i=1;i<=n;i++)v.push_back(i);
    ll ans=0;
    for(int i=3;i<=n;i++){
        ans+=i*(i-1);
    }
    // int pos=0;
    // int cnt=0;
    // ll tmp=1;
    // while(v.size()>=2){
    //     tmp*=v[pos];
    //     cnt++;
    //     if(cnt==3){
    //         cnt=0;
    //         ans+=tmp;
    //         tmp=v[pos];
    //     }
    //     if(cnt==2){
    //         v.erase(v.begin()+pos);
    //         if(pos==v.size())pos=0;
    //     }
    //     else{
    //         pos++;
    //         if(pos==v.size())pos=0;
    //     }
    // }
    cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}