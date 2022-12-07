#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll a[N];
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
        int flag=1;
        ll re=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ll k=i-1;
            if(a[i]+re<k){
                flag=0;
            }
            else{
                re+=(a[i]-k);
                if(re<0){
                    flag=0;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}