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
        int n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        string str;
        ll ans=0;
        cin>>str;
        if(c1+h<c0){
            c0=c1+h;
        }
        else if(c0+h<c1){
            c1=c0+h;
        }
        for(int i=0;i<str.length();i++){
            if(str[i]=='1')ans+=c1;
            else ans+=c0;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}