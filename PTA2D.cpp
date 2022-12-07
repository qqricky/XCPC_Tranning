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
    map<int,string>mp;
    string str;
    int n;
    int x;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>str>>x;
        a[i]=x;
        mp[x]=str;
        sum+=x;
    }
    double y=(double)sum/(2*n);
    double gg=114514341.0;
    int final;
    for(int i=1;i<=n;i++){
        if(fabs(a[i]-y)<gg){
            gg=fabs(a[i]-y);
            final=a[i];
        }
    }
    cout<<(int)y<<' '<<mp[final];
    //cout.flush();
    //system("pause");
    return 0;
}