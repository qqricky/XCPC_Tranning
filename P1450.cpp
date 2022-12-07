#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
ll f[N]={};
using namespace std;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c[5];
    int n;
    for(int i=1;i<=4;i++)cin>>c[i];
    cin>>n;
    f[0]=1;
    for(int j=1;j<=4;j++){
        for(int i=c[j];i<=100000;i++){
            f[i]+=f[i-c[j]];
        }
    }
    while(n--)
    {
        int d[5];
        for(int i=1;i<=4;i++)cin>>d[i];
        int s;
        cin>>s;
        ll sum=0;
        for(int j=1;j<=(1<<4)-1;j++){
            int cnt=0;
            int tmp=j;
            int val=0;
            for(int k=1;k<=4;k++,tmp/=2){
                if(tmp%2==1){
                    cnt++;
                    val+=(d[k]+1)*c[k];
                }
            }
            if(val>s)continue;
            if(cnt&1){
                sum-=f[s-val];
                //cout<<val<<endl;
            }
            else{
                sum+=f[s-val];
            }
        }
        sum+=f[s];
        cout<<sum<<endl;
    }
    //system("pause");
    return 0;
}