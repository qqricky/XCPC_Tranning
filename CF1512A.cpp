#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;

int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int tt=gcd(k,100);
        if(k!=100)
            cout<<100/tt<<endl;
        else cout<<1<<endl;
    }
    return 0;
}