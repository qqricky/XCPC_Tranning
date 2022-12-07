#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int num[33]={};
int gcd(int x,int y){
    return y ? gcd(y,x%y) : x;
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
        int n;
        cin>>n;
        int ans,tmp;
        int sum=0;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            cin>>tmp;
            sum+=tmp;
            for(int j=0;j<=30;j++){
                num[j]+=((tmp>>j)&1);
            }
        }
        if(!sum){
            for(int i=1;i<=n;i++)cout<<i<<' ';
            cout<<'\n';
            continue;
        }
        ans=0;
        for(int i=0;i<=30;i++){
            ans=gcd(ans,num[i]);
        }
        //cout<<"sjakf"<<ans<<'\n';
        for(int i=1;i<=ans;i++){
            if(ans%i==0)cout<<i<<' ';
            //cout<<'\n';
        }
        cout<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}