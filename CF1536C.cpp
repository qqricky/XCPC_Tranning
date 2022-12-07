#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int sumd[N];
int sumk[N];
int dp[N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        int n;
        read(n);
        memset(dp,0,sizeof(int)*(n+1));
        char ch;
        map<pair<int,int>,int>mp;
        sumd[0]=sumk[0]=0;
        for(int i=1;i<=n;i++){
            ch=getchar();
            if(ch=='D'){
                sumd[i]=sumd[i-1]+1;
                sumk[i]=sumk[i-1];
            }
            else{
                sumk[i]=sumk[i-1]+1;
                sumd[i]=sumd[i-1];
            }
        }
        for(int i=1;i<=n;i++){
            int tmp=gcd(sumk[i],sumd[i]);
            //cout<<"what   "<<tmp<<endl;
            if(mp[make_pair(sumd[i]/tmp,sumk[i]/tmp)]==0){
                dp[i]=1;
                mp[make_pair(sumd[i]/tmp,sumk[i]/tmp)]=i;
            }
            else{
                dp[i]=dp[mp[make_pair(sumd[i]/tmp,sumk[i]/tmp)]]+1;
                mp[make_pair(sumd[i]/tmp,sumk[i]/tmp)]=i;
            }
            cout<<dp[i]<<' ';
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}