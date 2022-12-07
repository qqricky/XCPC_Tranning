#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
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
        ll x,y,k;
        cin>>x>>y>>k;
        ll val=gcd(x,y);
        //system("pause");
        if(val==1){
            if(k==1)cout<<1<<endl;
            else cout<<-1<<endl;
        }
        else if(k>2*sqrt(val))cout<<-1<<endl;
        else{
            vector<ll>v;
            int flag=1;
            for(ll i=1;i*i<=val;i++){
                if(val%i==0){
                    k--;
                    v.push_back(i);
                    if(k==0){
                        flag=0;
                        cout<<val/i<<endl;
                        break;
                    }
                }
            }
            if(flag){
                for(int j=v.size()-1;j>=0;j--){
                    k--;
                    if(k==0){
                        flag=0;
                        cout<<v[j]<<endl;
                        break;
                    }
                }
                if(flag)cout<<-1<<endl;
            }
        }
    }
    return 0;
}