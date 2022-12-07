#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int mp[200][200]={};
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
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        int flag=1;
        if(n*a!=m*b)flag=0;
        if(!flag){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        memset(mp,0,sizeof(mp));
        int pos=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a;j++){
                if(pos>m)pos=1;
                mp[i][pos]=1;
                pos++;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<mp[i][j];
            }
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}