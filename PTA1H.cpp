#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>v;
    v.push_back(a[1]);
    for(int i=2;i<=n;i++){
        if(a[i]<v[v.size()-1])v.push_back(a[i]);
        else{
            int pos=lower_bound(v.begin(),v.end(),a[i],greater<int>())-v.begin();
            v[pos]=a[i];
        }
    }
    cout<<v.size();
    //system("pause");
    return 0;
}