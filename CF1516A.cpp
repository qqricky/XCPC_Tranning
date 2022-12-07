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
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        int pos=1;
        while(k)
        {
            if(pos==n)break;
            if(a[pos]<=k){
                a[n]+=a[pos];
                k-=a[pos];
                a[pos]=0;
                pos++;
            }
            else{
                a[pos]-=k;
                a[n]+=k;
                k=0;
            }
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        cout<<endl;
    }
    //system("pause");
    return 0;
}