#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int v[250];
int a[250];
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
        int cnt=0;
        memset(v,0,sizeof(v));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(v[a[i]])cnt++;
            v[a[i]]++;
        }
        sort(a+1,a+n+1);
        int t=unique(a+1,a+n+1)-a;
        for(int i=1;i<=n-cnt;i++)cout<<a[i]<<' ';
        for(int i=0;i<=100;i++){
            while(v[i]>1){
                cout<<i<<' ';
                v[i]--;
            }
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}