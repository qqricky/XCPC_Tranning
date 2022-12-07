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
    unsigned long long x=0;
    unsigned long long base=1;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        x+=base;
        base<<=1;
    }
    cout<<x;
    //system("pause");
    return 0;
}