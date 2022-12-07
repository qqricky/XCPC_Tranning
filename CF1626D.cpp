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
vector<int>v;
int num[N];
int s[N];
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
        memset(num,0,sizeof(int)*(n+2));
        memset(s,0,sizeof(int)*(n+2));
        int val;
        for(int i=1;i<=n;i++){
            cin>>val;
            num[val]++;
        }
        v.clear();
        int fl=0;
        for(int i=1;i<=n;i++){
            if(num[i]){
                v.push_back(num[i]);
                fl++;
                s[fl]=s[fl-1]+num[i];
            }
        }
        int ans=INF;
        for(int i=1;i<=n;i<<=1){
            for(int j=1;j<=n;j<<=1){
                int pos=0;
                int cnt1=0;
                while(cnt1+v[pos]<=i&&pos<v.size()){
                    cnt1+=v[pos];
                    pos++;
                }
                int cnt2=0;
                while(cnt2+v[pos]<=j&&pos<v.size()){
                    cnt2+=v[pos];
                    pos++;
                }
                int base=1;
                while(base<n-s[pos]){
                    base<<=1;
                }
                ans=min(ans,i-cnt1+j-cnt2+base-(n-s[pos]));
                //cout<<i<<' '<<j<<"@  "<<cnt1<<' '<<cnt2<<' '<<base-(n-s[pos])<<endl;
            }
        }
        
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}