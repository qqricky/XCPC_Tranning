#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[100];
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
        int cnt1=0;
        int cnt2=0;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]&1)cnt1++;
            else cnt2++;
        }
        int sum=(cnt1%2+cnt2%2);
        sort(a+1,a+n+1);
        int flag=0;
        if(sum==0)flag=1;
        if(sum==2){
            for(int i=2;i<=n;i++){
                if(a[i]-a[i-1]==1){
                    flag=1;
                    break;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}