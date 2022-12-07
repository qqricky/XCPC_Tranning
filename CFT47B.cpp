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
int suf[N][27];
set<int>mp[27];
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
        int n,m,k;
        cin>>n>>m>>k;
        string str1,str2;
        cin>>str1>>str2;
        for(int j=0;j<26;j++){
            suf[m][j]=0;
            mp[j].clear();
        }
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<26;j++){
                suf[i][j]=suf[i+1][j];
            }
            suf[i][str2[i]-'a']++;
        }
        for(int i=0;i+k-1<n;i++){
            mp[str1[i]-'a'].insert(str1[i+k-1]-'a');
        }
        ll ans=0;
        for(int i=0;i<m;i++){
            for(int x:mp[str2[i]-'a']){
                ans+=suf[i][x];
            }
        }
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}