#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int f[2*N]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum&1){
        cout<<0;
        return 0;
    }
    else{
        f[0]=1;
            for(int i=1;i<=n;i++){
                for(int j=sum/2;j>=a[i];j--){
                    f[j]|=f[j-a[i]];
                }
            }
        if(f[sum/2]==0){
            cout<<0;
            return 0;
        }
        for(int i=1;i<=n;i++){
            if(a[i]&1){
                cout<<1<<endl<<i;
                return 0;
            }
        }
        // for(int i=1;i<=n;i++){
        //     if(((sum-a[i])/2)&1){
        //         cout<<1<<endl<<a[i];
        //         return 0;
        //     }
        // }
            for(int i=1;i<=n;i++){
                if(f[sum/2-a[i]/2]==0){
                    cout<<1<<endl;
                    cout<<i;
                    return 0;
                }
            }
        cout<<0;
    }
    //system("pause");
    return 0;
}