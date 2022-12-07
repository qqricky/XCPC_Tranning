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

int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;string str;
        cin>>n>>str;
        ll ans=0;
        if(str=="Bob"){
            if(n<7){
                if(n<3){
                    ans=1;
                }else if(n<5){
                    ans=2;
                }else{
                    ans=3;
                }
            }else{
                n-=7;
                ans=3;
                ans+=n/5*2;
                int re=n%5;
                if(re>=1&&re<3){
                    ans++;
                }else if(re>=3){
                    ans+=2;
                }
            }
        }else{
            if(n<7){
                if(n<=3){
                    ans=1;
                }else if(n<=5){
                    ans=2;
                }else{
                    ans=3;
                }
            }else{
                n-=7;
                ans=3;
                ans+=n/5*2;
                int re=n%5;
                if(re>=1&&re<=3){
                    ans++;
                }else if(re>3){
                    ans+=2;
                }
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}