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
const ll ma=1e16;
ll pow_q(ll a,ll b){
    __int128 ans=1;
    __int128 aa=a;
    while(b){
        if(b&1)ans*=aa;
        if(ans>=(__int128)100000000000000000){
            return 100000000000000001;
        }
        b>>=1;
        aa*=aa;
    }
    return ans;
}
string str=" codeforces";
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll k;
    cin>>k;
    ll tot=1;
    ll base=1;
    while(pow_q(base,10)<=k){
        base++;
    }
    base--;
    tot=pow_q(base,10);
    int cnt=0;
    while(tot<k){
        tot=tot*(base+1)/base;
        cnt++;
    }
    for(int i=1;i<=10;i++){
        int num=base;
        if(cnt){
            num++;
            cnt--;
        }
        for(int j=1;j<=num;j++){
            cout<<str[i];
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}