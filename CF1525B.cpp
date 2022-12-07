#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        a[0]=0;
        int flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]!=a[i-1]+1)flag=0;
        }
        if(flag){
            cout<<0<<endl;
        }
        else if(a[1]==1||a[n]==n){
            cout<<1<<endl;
        }
        else if(a[1]==n&&a[n]==1){
            cout<<3<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}