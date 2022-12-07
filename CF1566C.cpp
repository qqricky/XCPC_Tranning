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
int sum[N];
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
        string str1,str2;
        cin>>str1>>str2;
        sum[0]=sum[n+1]=114514;
        int pos=0;
        for(int i=0;i<n;i++){
            sum[i+1]=str2[i]+str1[i]-'0'-'0';
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(sum[i]==1)ans+=2;
            else if(sum[i]==0){
                if(sum[i-1]==2&&pos!=i-1){
                    pos=i-1;
                    ans+=2;
                }
                else if(sum[i+1]==2){
                    ans+=2;
                    pos=i+1;
                    i++;
                }
                else{
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}