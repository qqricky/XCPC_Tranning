#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[5];
int d[5]={};
int ck()
{
    
}
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
        memset(d,0,sizeof(d));
        for(int i=1;i<=4;i++){
            cin>>a[i];
            if(a[i]>n-2)d[i]=a[i]-(n-2);
        }

    }
    //system("pause");
    return 0;
}