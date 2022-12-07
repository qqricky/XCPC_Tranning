#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
struct node
{
    ll up,down;
};
__int128 gcd(__int128 a,__int128 b){
    return b ? gcd(b,a%b) : a;
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
ll a[N];
int cnt[40]={};
void output(__int128 x,__int128 y){
    string s1,s2;
    while(x){
        int k=x%10;
        s1+=(char)('0'+k);
        x/=10;
    }
    if(s1.size()==0){
        s1='0';
    }
    while(y){
        int k=y%10;
        s2+=(char)('0'+k);
        y/=10;
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    cout<<s1<<'/'<<s2;
}
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        for(int j=0;j<=15;j++){
            if((a[i]>>j)&1){
                cnt[j]++;
            }
        }
    }
    __int128 up=0;
    for(int i=1;i<=n;i++){
        __int128 res=0;
        for(int j=0;j<=15;j++){
            if(cnt[j]){
                cnt[j]--;
                res+=(1ll<<j);
            }
        }
        up+=(res*n-sum)*(res*n-sum);
    }
    __int128 nn=n*n*n;
    __int128 x=(up/gcd(up,nn));
    __int128 y=(n*n*n)/gcd(up,nn);
    output(x,y);
    // cout.flush();
    // system("pause");
    return 0;
}