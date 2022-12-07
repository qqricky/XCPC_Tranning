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
int bit[61]={};
int cnt=0,num=0;
ll d[64];
int n,k;
bool ck(ll x){
    int nn=0;
    while(x){
        nn+=x%2;
        x/=2;
    }
    if(nn!=k)return 0;
    return 1;
}
void add(ll x){
    for(int i=n-1;i>=0;i--){
        if(x&(1ll<<i)){
            if(d[i])x^=d[i];
            else{
                if(ck(x)){
                    d[i]=x;
                    cnt++;
                    break;
                }
                else{
                    return;
                }
            }
        }
    }
}
ll solve(){
    ll ans=0;
    for(int i=0;i<n;i++){
        if(bit[i])
        ans=(ans+(1ll<<i));
    }
    return ans;
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
        cin>>n>>k;
        memset(d,0,sizeof(d));
        memset(bit,0,sizeof(bit));
        cnt=0,num=0;
        for(int i=n-1;i>=n-k;i--){
            bit[i]=1;
        }
        ll tmp=0;
        for(int i=0;i<k;i++){
            tmp+=(1ll<<i);
        }
        ll xx=0;
        while(1){
            xx++;
            if(xx>(1ll<<n)-1){
                cout<<-1<<'\n';
                break;
            }
            num++;
            //next_permutation(bit,bit+n);
            add(xx);
            if(cnt==n)break;
            if(num>=50000){
                cout<<-1<<'\n';
                break;
            }
        }
        if(cnt==n){
            sort(d,d+n);
            for(int i=0;i<n;i++)cout<<d[i]<<' ';
            cout<<'\n';
        }
    }
    cout.flush();
    system("pause");
    return 0;
}