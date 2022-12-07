#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int ans=INF;
int calc(int x)
{
    int cnt=0;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            cnt=i;
            break;
        }
    }
    if(!cnt)cnt=x-1;
    return cnt;
}
void sech(int acu,int x)
{
    if(x==1){
        ans=min(ans,acu);
        return ;
    }
    if(acu>ans)return ;
    int k=calc(x);
    ans=min(ans,k+acu);
    sech(acu+1,x-1);
}
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
        ans=INF;
        int n;
        cin>>n;
        sech(0,n);
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}