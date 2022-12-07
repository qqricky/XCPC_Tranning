#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
const ll mod=1e7;
int a[105];
int f[10008];
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
        ll sum=0;
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
            for(int j=sum;j>=a[i];j--){
                //cout<<f[j-a[i]]<<endl;
                f[j]+=f[j-a[i]];
                f[j]%=mod;
            }
        }
        ll ans1=0;
        ll ans2=0;
        for(int i=0;i<=sum;i++){
            if(f[i]){
                //cout<<i<<"  "<<f[i]<<endl;
                if(i>sum-i){
                    ans1=(ans1+(ll)(i-(sum-i))*f[i])%mod;
                }
                else{
                    ans2=(ans2+(ll)(sum-i-i)*f[i])%mod;
                }
            }
        }
        cout<<(ans1+ans2)%mod<<endl;
    }
    //system("pause");
    return 0;
}