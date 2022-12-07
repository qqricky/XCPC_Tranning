#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
int a[105]={};
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
        memset(a,0,sizeof(a));
        int flag;
        if(n&1){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(i%2==1&&j%2==0)cout<<1<<' ';
                    else if(i%2==0&&j%2==1)cout<<1<<' ';
                    else cout<<-1<<' ';
                }
            }
        }
        else{
            for(int i=1;i<n;i++){
                int j;
                if(i&1){
                    cout<<0<<' ';
                    j=i+2;
                }
                else
                    j=i+1;
                for(;j<=n;j++){
                    if(i%2==1&&j%2==0)cout<<1<<' ';
                    else if(i%2==0&&j%2==1)cout<<1<<' ';
                    else cout<<-1<<' ';
                }
            }
        }
        cout<<"\n";
    }
    //system("pause");
    return 0;
}