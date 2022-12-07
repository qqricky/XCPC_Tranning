#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[N];
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
        int n,x;
        cin>>n>>x;
        int flag=1;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt+=a[i];
            if(i>1&&a[i]!=a[i-1])flag=0;
        }
        if((flag&&x%a[1]==0&&x<cnt)||cnt==x){
            cout<<"NO"<<endl;
            continue;
        }
        sort(a+1,a+n+1);
        ll sum=0;
        int f=1;
        int pos;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum==x){
                pos=i;
                for(int j=i+1;j<=n;j++){
                    if(a[j]!=a[i]){
                        swap(a[j],a[i]);
                        break;
                    }
                    if(j==n)f=0;
                }
            }
        }
        if(f){
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<a[i]<<" ";
            cout<<endl;
        }
        else{
            swap(a[n],a[1]);
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<a[i]<<" ";
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}