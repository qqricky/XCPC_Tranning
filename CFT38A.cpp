#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int x[5],y[5];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        char ch;
        string a,b;
        cin>>a>>b;
        memset(x,0,sizeof(x)),memset(y,0,sizeof(y));
        for(int j=0;j<4;j++){
            int tmp=a[j]-'0';
            int to=b[j]-'0';
            while(tmp!=to){
                tmp=(tmp+1)%10;
                x[j+1]++;
            }
            tmp=a[j]-'0';
            to=b[j]-'0';
            while(tmp!=to){
                tmp=(tmp-1+10)%10;
                y[j+1]++;
            }
        }
        int ans=0;
        for(int j=1;j<=4;j++){
            ans+=min(x[j],y[j]);
        }
        ans=min(ans,max(x[1],x[2])+max(y[3],y[4]));
        ans=min(ans,max(y[1],y[2]),max(x[3],x[4]));
        ans=min(ans,max(x[1],max(x[2],max(x[3],x[4]))));
        ans=min(ans,max(y[1],max(y[2],max(y[3],y[4]))));
        ans=min(ans,max(y[2],y[3])+x[1]+x[4]);
        ans=min(ans,max(x[2],x[3])+y[1]+y[4]);
        ans=min(ans,x[1]+max(y[2],max(y[3],y[4])));
        ans=min(ans,y[1]+max(x[2],max(x[3],x[4])));
        ans=min(ans,x[4]+max(y[2],max(y[3],y[1])));
        ans=min(ans,y[4]+max(x[2],max(x[3],x[1])));
        cout<<ans<<'\n';
    }
    cout.flush();
    system("pause");
    return 0;
}