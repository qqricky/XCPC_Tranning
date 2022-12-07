#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5070; 
using namespace std;
ll f[N];
int tag[N];
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
        int n;
        cin>>n;
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)cin>>tag[i];
        for(int i=1;i<=n;i++)cin>>s[i];
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=1;j--){
                if(tag[i]!=tag[j]){
                    ll tt=f[j];
                    f[j]=max(f[j],f[i]+abs(s[i]-s[j]));
                    f[i]=max(f[i],tt+abs(s[i]-s[j]));
                }
            }
        }
        cout<<*max_element(f+1,f+1+n)<<endl;
    }
    //system("pause");
    return 0;
}