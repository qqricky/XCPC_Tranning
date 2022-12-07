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
const ll mod=1e9+7;
ll fib[N]={};
void init(){
    fib[1]=1;
    fib[2]=2;
    for(int i=3;i<=1e5;i++){
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    init();
    string str;
    cin>>str;
    str+='*';
    int cnt=0;
    ll ans=1;
    bool flag=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='m'||str[i]=='w'){
            cout<<0;
            return 0;
        }
        if(str[i]=='u'){
            cnt++;
        }
        else{
            if(cnt)ans=(ans*fib[cnt])%mod;
            cnt=0;
        }
    }
    for(int i=0;i<str.length();i++){
        if(str[i]=='n'){
            cnt++;
        }
        else{
            if(cnt)ans=(ans*fib[cnt])%mod;
            cnt=0;
        }
    }
    cout<<ans%mod;
    cout.flush();
    //system("pause");
    return 0;
}