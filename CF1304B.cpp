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
string s[105];
int mid[105]={};
int v[105]={};
vector<string>raw;
vector<string>re;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    //cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        string tmp=s[i];
        reverse(tmp.begin(),tmp.end());
        if(tmp==s[i])mid[i]=1;
    }
    for(int i=1;i<=n;i++){
        if(v[i])continue;
        for(int j=i+1;j<=n;j++){
            bool f=1;
            for(int k=0;k<m;k++){
                if(s[i][k]!=s[j][m-k-1]){
                    f=0;
                    break;
                }
            }
            if(f){
                raw.push_back(s[i]);
                re.push_back(s[j]);
                v[j]=1;
                v[i]=1;
                break;
            }
        }
    }
    string ans;
    for(int i=1;i<=n;i++){
        if(!v[i]&&mid[i]){
            ans=s[i];
            break;
        }
    }
    for(int i=0;i<re.size();i++){
        ans+=re[i];
        ans=raw[i]+ans;
    }
    cout<<ans.size()<<"\n"<<ans<<endl;
    //system("pause");
    return 0;
}