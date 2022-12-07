#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e2+10; 
using namespace std;
char a[N][N];
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
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        int cnt1=a[1][2]-'0'+a[2][1]-'0';
        int cnt2=a[n][n-1]-'0'+a[n-1][n]-'0';
        if(cnt1==2){
            cout<<cnt2<<endl;
            if(a[n][n-1]=='1'){
                cout<<n<<' '<<n-1<<endl;
            }
            if(a[n-1][n]=='1'){
                cout<<n-1<<' '<<n<<endl;
            }
            continue;
        }
        if(cnt1==0){
            cout<<2-cnt2<<endl;
            if(a[n][n-1]=='0'){
                cout<<n<<' '<<n-1<<endl;
            }
            if(a[n-1][n]=='0'){
                cout<<n-1<<' '<<n<<endl;
            }
            continue;
        }
        if(cnt2==2){
            cout<<cnt1<<endl;
            if(a[1][2]=='1'){
                cout<<1<<' '<<2<<endl;
            }
            if(a[2][1]=='1'){
                cout<<2<<' '<<1<<endl;
            }
            continue;
        }
        if(cnt2==0){
            cout<<2-cnt1<<endl;
            if(a[1][2]=='0'){
                cout<<1<<' '<<2<<endl;
            }
            if(a[2][1]=='0'){
                cout<<2<<' '<<1<<endl;
            }
            continue;
        }
        cout<<2<<endl;
        if(a[1][2]=='0'){
            cout<<1<<' '<<2<<endl;
        }
        else{
            cout<<2<<' '<<1<<endl;
        }
        if(a[n][n-1]=='1'){
            cout<<n<<' '<<n-1<<endl;
        }
        else{
            cout<<n-1<<' '<<n<<endl;
        }
    }
    //system("pause");
    return 0;
}