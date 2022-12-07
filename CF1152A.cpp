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
    int n,m;
    cin>>n>>m;
    ll cnt0=0,cnt1=0,cnt2=0,cnt3=0;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp&1)cnt0++;
        else cnt1++;
    }
    for(int i=1;i<=m;i++){
        cin>>tmp;
        if(tmp&1)cnt2++;
        else cnt3++;
    }
    cout<<min(cnt0,cnt3)+min(cnt1,cnt2);
    cout.flush();
    //system("pause");
    return 0;
}