#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
const int N=1e5+10; 
using namespace std;

int main()
{
    freopen("TestCase.in","r",stdin);
    freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        ll dis=b-a;
        int flag=0;
        if(a*2==b)flag=1;
        if(a>dis&&(a-dis)%3==0)flag=1;
        else{
            a-=dis;
            b-=2*dis;
            if(a>0&&(a%3==0))flag=1;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        //system("pause");
    }
    return 0;
}