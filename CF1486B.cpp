#include <bits/stdc++.h>
#define ll long long
const int N=1e4+10; 
using namespace std;

struct node
{
    ll x,y;
    ll z;
}a[N];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
bool cmp1(node a,node b)
{
    return a.y<b.y;
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
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y;
        }
        if(n&1){
            cout<<1<<endl;
            continue;
        }
        ll midx;
        if(n&1)midx=1;
        else{
            sort(a+1,a+n+1,cmp);
            midx=a[n/2+1].x-a[n/2].x+1;
        }
        ll midy;
        if(n&1)midy=1;
        else{
            sort(a+1,a+n+1,cmp1);
            midy=a[n/2+1].y-a[n/2].y+1;
        }
        cout<<midx*midy<<endl;
    }
    //system("pause");
    return 0;
}