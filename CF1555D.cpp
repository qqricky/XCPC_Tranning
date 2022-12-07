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
string tp[7]={"","abc","acb","bac","bca","cab","cba"};
int cnt[7][N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    str=' '+str;
    int l,r;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(str[i]!=tp[j][i%3]){
                cnt[j][i]=cnt[j][i-1]+1;
            }
            else{
                cnt[j][i]=cnt[j][i-1];
            }
        }
    }
    while(m--)
    {
        cin>>l>>r;
        int ans=INF;
        for(int i=1;i<=6;i++){
            ans=min(ans,cnt[i][r]-cnt[i][l-1]);
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}