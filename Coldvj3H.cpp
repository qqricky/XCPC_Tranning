#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[1070];
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n)
    {
        memset(f,0,sizeof(f));
        a[0]=0;
        f[n+1]=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i])f[i]=max(f[i],f[j]+a[i]);
            }
        }
        for(int j=n;j>=0;j--){
                f[n+1]=max(f[n+1],f[j]);
        }
        cout<<f[n+1]<<endl;
        cin>>n;
    }
    //system("pause");
    return 0;
}