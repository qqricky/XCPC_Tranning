#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int a[N];
int l[N];
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
    for(int i=1;i<=m;i++)cin>>l[i];
    set<int>s;
    a[n+1]=0;
    for(int i=n;i>=1;i--){
        if(s.count(a[i])==0){
            s.insert(a[i]);
            a[i]=a[i+1]+1;
        }
        else{
            a[i]=a[i+1];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<a[l[i]]<<"\n";
    }
    //system("pause");
    return 0;
}