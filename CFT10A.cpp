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
        string str;
        cin>>str;
        int len=str.length();
        str=' '+str;
        int ans=0;
        for(int i=1;i<=len;i++){
            if(str[i]=='H')ans++;
            else if(str[i]=='O')ans+=16;
            else if(str[i]=='C')ans+=12;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}