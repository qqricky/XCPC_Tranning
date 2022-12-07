#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
bool check(int x,int d)
{
    while(x){
        if(d==x%10)return 1;
        x/=10;
    }
    return 0;
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
        int n,d;
        cin>>n>>d;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp>=(d+1)*10){
                cout<<"YES"<<endl;
                continue;
            }
            int flag=0;
            if(check(tmp,d))flag=1;
            if(tmp%d==0)flag=1;
            if(flag)goto paris;
            while(tmp>=d){
                tmp-=d;
                if(tmp%10==0){
                    flag=1;break;
                }
                if(check(tmp,d)){
                    flag=1;break;
                }
            }
            paris:;
            if(flag)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    //system("pause");
    return 0;
}