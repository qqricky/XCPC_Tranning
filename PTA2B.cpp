#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[12];
int x,y;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin>>x>>y;
    int base=26;
    int div=1;
    while(y>base){
        base*=26;
        div++;
    }
    div--;
    base/=26;
    for(int i=1;i<=12;i++)a[i]=26;
    for(int i=div+1;i>=1;i--){
        //cout<<x-i+1<<'Q'<<26-(y/base)<<endl;
        a[x-i+1]=26-(y/base);
        y-=((y/base)*base);
        base/=26;
    }
    for(int i=1;i<=x;i++)cout<<(char)(a[i]+'a'-1);
    cout.flush();
    system("pause");
    return 0;
}