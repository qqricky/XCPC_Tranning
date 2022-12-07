#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=350; 
using namespace std;
int a[N];
int l[N],r[N];
int s[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        s[l[i]]++;
        s[r[i]+1]--;
    }

    //system("pause");
    return 0;
}