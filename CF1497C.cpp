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
    int n,k;
    while(t--)
    {
        cin>>n>>k;
        if(n&1){
            cout<<1<<' '<<n/2<<' '<<n/2<<endl;
        }
        else if(n%4==0){
            cout<<n/4<<' '<<n/4<<' '<<n/2<<endl;
        }
        else{
            cout<<n/2-1<<' '<<n/2-1<<' '<<2<<endl;
        }
    }
    
    //system("pause");
    return 0;
}