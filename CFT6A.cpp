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
    int n,m;
    cin>>n>>m;
    string a[22];
    string b[22];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i]; 
    int q;
    cin>>q;
    int tmp;
    for(int i=1;i<=q;i++){
        cin>>tmp;
        int x=tmp%n;
        int y=tmp%m;
        if(x==0)x=n;
        if(y==0)y=m;
        cout<<a[x]<<b[y]<<endl;
    }
    //system("pause");
    return 0;
}