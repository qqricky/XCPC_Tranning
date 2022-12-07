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
        for(int j=0;j<(1<<4);j++){
            for(int k=0;k<(1<<4);k++){
                for(int s=0;s<4;s++){
                    if((j>>s)&1)x[s+1]+=10;
                    if((k>>s)&1)y[s+1]+=10;
                }
                int sum=0;
                ans=min(ans,max(x[1],x[2])+max(y[3],y[4]));
                ans=min(ans,max(y[1],y[2])+max(x[3],x[4]));
                ans=min(ans,max(x[1],x[2])+max(x[3],x[4]));
                ans=min(ans,max(y[1],y[2])+max(y[3],y[4]));
                ans=min(ans,max(x[1],x[2])+min(y[3],x[3])+min(y[4],x[4]));
                ans=min(ans,max(y[1],y[2])+min(y[3],x[3])+min(y[4],x[4]));
                ans=min(ans,max(x[3],x[4])+min(y[1],x[1])+min(y[2],x[2]));
                ans=min(ans,max(y[3],y[4])+min(y[1],x[1])+min(y[2],x[2]));
                ans=min(ans,max(y[2],y[3])+x[1]+x[4]);
                ans=min(ans,max(x[2],x[3])+y[1]+y[4]);
                ans=min(ans,max(y[2],y[3])+min(y[1],x[1])+min(y[4],x[4]));
                ans=min(ans,max(x[2],x[3])+min(y[1],x[1])+min(y[4],x[4]));
                sum=0;
                for(int j=1;j<=4;j++)sum+=x[j];
                for(int j=2;j<=4;j++)sum-=min(x[j],x[j-1]);
                ans=min(ans,sum);
                sum=0;
                for(int j=1;j<=4;j++)sum+=y[j];
                for(int j=2;j<=4;j++)sum-=min(y[j],y[j-1]);
                ans=min(ans,sum);
                sum=min(x[1],y[1]);
                for(int j=2;j<=4;j++)sum+=y[j];
                for(int j=3;j<=4;j++)sum-=min(y[j],y[j-1]);
                ans=min(ans,sum);
                sum=min(x[1],y[1]);
                for(int j=2;j<=4;j++)sum+=x[j];
                for(int j=3;j<=4;j++)sum-=min(x[j],x[j-1]);
                ans=min(ans,sum);
                sum=min(x[4],y[4]);
                for(int j=1;j<=3;j++)sum+=y[j];
                for(int j=2;j<=3;j++)sum-=min(y[j],y[j-1]);
                ans=min(ans,sum);
                sum=min(x[4],y[4]);
                for(int j=1;j<=3;j++)sum+=x[j];
                for(int j=2;j<=3;j++)sum-=min(x[j],x[j-1]);
                ans=min(ans,sum);
                for(int s=0;s<4;s++){
                    if((j>>s)&1)x[s+1]-=10;
                    if((k>>s)&1)y[s+1]-=10;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}