#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=10000; 
using namespace std;
ll a[N];
ll f[N];
ll s[N];
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
        f[1]=f[0]=0;
        memset(s,0,sizeof(s));
        ll n;
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i]=f[i-1]+s[i];
            if(a[i]>=2){
                s[i+2]++;
                s[min(n+5,i+a[i]+1)]--;
            }
            if(a[i]-f[i]>1){
                sum+=a[i]-f[i]-1;
                //cout<<i<<"QQ"<<sum<<endl;
            }
            else if(a[i]-f[i]<1){
                int k=f[i]-a[i]+1;
                s[i+1]+=k;
                s[i+2]-=k;
            }
            //cout<<i<<'Q'<<f[i]<<endl;
        }
        cout<<sum<<endl;
    }
    //system("pause");
    return 0;
}