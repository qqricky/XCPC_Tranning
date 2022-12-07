#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,k,x;
    cin>>n>>k>>x;
    ll ans[10000][2]={};
    int cnt=0;
    ll base=x;
    int flag=1;
    int num=0;
    ll sum=0;
    while(n){
        cnt+=n%x;
        ans[num][0]=n%x;
        num++;
        n/=x;
        base*=x;
    }
    num--;
    base/=x;
    ll go=0;
    if(cnt>k)flag=0;
    else{
        if((k-cnt)%(x-1))flag=0;
        go=(k-cnt)/(x-1);
    }
    if(!flag){cout<<"NO"<<endl;return 0;}
    else{
        int pos=num;
        for(int i=num;i>=1;i--){
            if(go==0)break;
            else{
                if(go>=ans[i][0]){
                    go-=ans[i][0];
                    ans[i-1][0]+=(ans[i][0]*(x));
                    ans[i][0]=0;
                }
                else{
                    ans[i][0]-=go;
                    ans[i-1][0]+=go*x;
                    go=0;
                }
            }
        }
    }
    if(go)cout<<"NO"<<endl;
    else {
        cout<<"YES"<<endl;
        base/=x;
        for(int i=num;i>=0;i--){
            for(int j=1;j<=ans[i][0];j++){
                cout<<base<<' ';
            }
            base/=x;
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}