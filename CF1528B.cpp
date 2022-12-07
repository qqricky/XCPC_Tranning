#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int cnt=0;
vector<int>v;
int sum;
int a[N];
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
        int mi=INF;
        int num=0;
        int flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(i>1&&a[i]!=a[i-1])flag=0;
            if(a[i]<mi){
                num=1;
                mi=a[i];
            }
            else if(a[i]==mi){
                num++;
            }
        }
        if(flag)cout<<0<<endl;
        else cout<<n-num<<endl;
    }
    system("pause");
    return 0;
}