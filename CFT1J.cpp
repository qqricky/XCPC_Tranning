#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
char a[100][100];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int flag=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n-1;i++){
            for(int j=1;j<=n-1;j++){
                if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0'){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}