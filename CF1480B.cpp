#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[N],b[N];
ll x,y;
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
        cin>>x>>y;
        int n;
        cin>>n;
        int maxx=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            cin>>b[i];
            if(x>=b[i]){
                y-=a[i];
                maxx=max(maxx,a[i]);
            }
            else{
                ll num=b[i]/x+((b[i]%x)>0);
                y-=a[i]*num;
                maxx=max(maxx,a[i]);
            }
        }
        int flag=0;
        if(y+maxx>0)flag=1;
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}