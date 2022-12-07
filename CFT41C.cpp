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
ll p[N+5],tot;
bool v[N+5];
ll div1(ll n){
	ll cnt=0;
	for(int i = 0;i < tot;++i){
		if(n==1) break;
		while(n%p[i]==0) n/=p[i],++cnt;
	}
	if(n!=1) ++cnt;
	return cnt;
}
void init(){
	for(int i = 2;i <= N;++i)
		if(!v[i]){
			p[tot++] = i;
			for(int j = 2;i*j <= N;++j) v[i*j] = 1;
		}
}
struct node
{
    ll x,cnt;
    bool operator<(const node &b){
        return x<b.x;
    }
}nd[N];
int ncnt=0;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a,b;
    int t;
    cin>>t;
    init();
    while(t--){
        cin>>a>>b;
        if(a>b)swap(a,b);
        ll val=b-a;
        for(ll i=2;i*i<=val;i++){
            if(val%i==0){
                nd[++ncnt].x=i;
                nd[ncnt].cnt=div1(i);
                nd[++ncnt].x=val/i;
                nd[ncnt].cnt=div1(val/i);
            }
        }
        sort(nd+1,nd+ncnt);
    }
    cout.flush();
    system("pause");
    return 0;
}