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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        if(k>=n){
            cout<<1<<endl;
            continue;
        }
        else{
            int flag=1;
            vector<ll>v;
            for(ll i=2;(i*i)<=n;i++){
                if((n%i)==0){
                    v.push_back(n/i);
                    if((n/i)>k)continue;
                    cout<<i<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag){
            for(int j=v.size()-1;j>=0;j--){
                if(n%v[j]==0){
                    if(n/v[j]>k)continue;
                    cout<<v[j]<<endl;
                    flag=0;
                    break;
                }
            }
            }
            if(flag)cout<<n<<endl;
        }
    }
    //system("pause");
    return 0;
}