#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[N];
int a[N];
int c[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>n>>m;
    while(m+n)
    {
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>c[i];
        f[0]=1;
        int used[N];
        for(int i=1;i<=n;i++){
            memset(used,0,sizeof(used));
            for(int j=a[i];j<=m;j++){
                if(!f[j]&&f[j-a[i]]&&used[j-a[i]]<c[i])
                    f[j]=1,used[j]=used[j-a[i]]+1;
            }
        }
        ll cnt=0;
        for(int i=1;i<=m;i++)cnt+=f[i];
        cout<<cnt<<"\n";
        cin>>n>>m;
    }
    //system("pause");
    return 0;
}