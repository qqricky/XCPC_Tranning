#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int mi[2][11];
int ma[2][11];
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
        memset(mi,0x3f,sizeof(mi));
        memset(ma,0,sizeof(ma));
        char ch;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>ch;
                int x=ch-'0';
                ma[1][x]=max(ma[1][x],j);
                mi[1][x]=min(mi[1][x],j);
                ma[0][x]=max(ma[0][x],i);
                mi[0][x]=min(mi[0][x],i);
            }
        }
        for(int i=0;i<=9;i++){
            if(ma[1][i]==0||ma[1][i]==mi[1][i]&&ma[0][i]==mi[1][i]){
                cout<<0<<' ';
                continue;
            }
            if(ma[0][i]==mi[0][i]){
                cout<<max(n-ma[0][i],ma[0][i]-1)*(ma[1][i]-mi[1][i])<<' ';
            }
            else if(mi[1][i]==ma[1][i]){
                cout<<max(n-ma[1][i],ma[1][i]-1)*(ma[0][i]-mi[0][i])<<' ';
            }
            else{
                cout<<"qqq"<<ma[1][i]<<' '<<mi[1][i]<<endl;
                cout<<"QQQ"<<ma[0][i]<<' '<<mi[0][i]<<endl;
                int ans=max((n-mi[1][i])*(ma[0][i]-mi[0][i]),(ma[1][i]-1)*(ma[0][i]-mi[0][i]));
                ans=max(ans,(n-mi[0][i])*(ma[1][i]-mi[1][i]));
                ans=max(ans,(ma[0][i]-1)*(ma[1][i]-mi[1][i]));
                cout<<ans<<' ';
            }
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}