#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
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
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        ll x=0,y=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                if(!(a[i]&1))x+=a[i];
            }
            else{
                if(a[i]&1)y+=a[i];
            }
        }
        if(x>y)cout<<"Alice"<<endl;
        else if(x<y)cout<<"Bob"<<endl;
        else cout<<"Tie"<<endl;
    }
    //system("pause");
}