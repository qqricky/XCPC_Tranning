#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

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
        int x=0;
        if(n>k)x+=n-k;
        cout<<x+k/2<<endl;
        for(int i=k+1;i<=n;i++)cout<<i<<' ';
        for(int i=(k+1)/2;i<k;i++)cout<<i<<' ';
        cout<<endl;
    }
    //system("pause");
    return 0;
}