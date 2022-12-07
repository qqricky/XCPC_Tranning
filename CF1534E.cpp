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
int n,k;
ll ask(int st){
    cout<<'?'<<' ';
    for(int i=0;i<k&&st+i<=n;i++){
        cout<<st+i<<' ';
    }
    if(st+k-1>n){
        for(int i=1;i<=k-(n-st+1);i++){
            cout<<i<<' ';
        }
    }
    cout<<"\n";
    cout.flush();
    ll tmp;
    read(tmp);
    return tmp;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    read(n),read(k);
    if((n%k)&1){
        ll ans=0;
        if(n%(n%k)&1 || ( (n%(n%k)==0)&&((n/(n%k))&1) ) ){
            cout<<-1;
            return 0;
        }
        else if(n%(n%k)==0){
            int kk=n%k;
            for(int i=1;i<=n;i+=kk){
                ans^=ask(i);
            }
            cout<<"! "<<ans;
            return 0;
        }
        int kk=n%k;
        for(int i=1;i+kk-1<=n;i+=kk){
            ans^=ask(i+kk);
        }
        int stt=n-n%kk+1;
        n%=kk;
        int k1=kk-n/2;
        cout<<'?'<<' ';
        for(int i=k1+1;i-k1<=k-n/2;i++)cout<<i<<' ';
        for(int i=stt;i<=stt+n/2-1;i++)cout<<i<<' ';
        cout<<"\n";
        cout.flush();
        ll tmp;
        read(tmp);
        ans^=tmp;
        cout<<'?'<<' ';
        for(int i=k1+1;i-k1<=k-n/2;i++)cout<<i<<' ';
        for(int i=stt+n/2;i<=stt+n-1;i++)cout<<i<<' ';
        cout<<"\n";
        cout.flush();
        read(tmp);
        ans^=tmp;
        cout<<"! "<<ans;
        return 0;
    }
    ll ans=0;
    for(int i=1;i+k-1<=n;i+=k){
        ans^=ask(i);
    }
    int stt=n-n%k+1;
    n%=k;
    int k1=k-n/2;
    cout<<'?'<<' ';
    for(int i=1;i<=k1;i++)cout<<i<<' ';
    for(int i=stt;i<=stt+n/2-1;i++)cout<<i<<' ';
    cout<<endl;
    cout.flush();
    ll tmp;
    read(tmp);
    ans^=tmp;
    cout<<'?'<<' ';
    for(int i=1;i<=k1;i++)cout<<i<<' ';
    for(int i=stt+n/2;i<=stt+n-1;i++)cout<<i<<' ';
    cout<<endl;
    cout.flush();
    read(tmp);
    ans^=tmp;
    cout<<"! "<<ans;
    cout.flush(); 
    //system("pause");
    return 0;
}