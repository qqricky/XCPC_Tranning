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
int cnt[102];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        str=' '+str;
        cnt[0]=0;
        for(int i=1;i<=n;i++){
            if(str[i]=='a')cnt[i]=cnt[i-1]+1;
            else cnt[i]=cnt[i-1];
        }
        cnt[n+1]=cnt[n];
        bool flag=1;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j+=2){
                if(cnt[j]-cnt[i-1]==(j-i+1)/2){
                    cout<<i<<' '<<j<<'\n';
                    flag=0;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag)cout<<"-1 -1\n";
    }
    cout.flush();
    //system("pause");
    return 0;
}