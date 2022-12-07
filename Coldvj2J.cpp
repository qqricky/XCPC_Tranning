#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#define ll long long
const int N=1e5+10; 
using namespace std;
const ll mod=1000000007;
ll pow_Q(ll a,ll b)
{
    ll ans=1,base=a;
    while(b!=0)
    {
        if(b&1)ans=(ans*base)%mod;
        base=(base*base)%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    while(cin>>str){
    ll acu=0;
    if(str[str.length()-1]=='0'){
        int pos=str.length()-1;
        while(str[pos]=='0')
        {
            str[pos]='9';
            pos--;
        }
        str[pos]=str[pos]-1;
        if(str[0]=='0')str.erase(0,1);
    }
    else{
        str[str.length()-1]-=1;
    }
    for(int i=0;i<=str.length()-1;i++){
        acu=(acu*10+str[i]-'0')%(mod-1);
    }
    cout<<pow_Q(2,acu)<<endl;
    }
    //cout.flush();
    //system("pause");
    //return 0;
}