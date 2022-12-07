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
int num[64]={};
int test[64];
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
        int n;
        cin>>n;
        memset(num,0,sizeof(num));
        int ans=0;
        int ma=0;
        for(int i=1;i<=n;i++){
            ll x;
            cin>>x;
            for(int j=0;j<=32;j++){
                if(x&(1ll<<j)){
                    ma=max(ma,j);
                    num[j]++;
                }
            }
        }
        //int mi=INF;
        // for(int j=0;j<=ma;j++){
        //     mi=min(mi,num[j]);
        // }
        // ans=mi;
        // for(int j=0;j<=ma;j++){
        //     num[j]-=mi;
        // }
        while(ma>=0){
            while(ma>=0&&num[ma]<=0)ma--;
            if(ma<0)break;
            bool is=0;
            test[ma+1]=0;
            for(int j=0;j<=ma;j++)test[j]=num[j];
            for(int j=0;j<=ma;j++){
                if(test[j]<=0){
                    test[j]++;
                    test[j+1]--;
                }
                else{
                    test[j]--;
                }
            }
            if(test[ma+1]<0)is=1; 
            ans++;
            if(is){
                for(int j=0;j<ma;j++){
                    if(num[j]<=0){
                        num[j]++;
                        num[j+1]--;
                    }
                    else{
                        num[j]--;
                    }
                }
            }
            else{
                for(int j=0;j<=ma;j++){
                    if(num[j]<=0){
                        num[j]++;
                        num[j+1]--;
                    }
                    else{
                        num[j]--;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}