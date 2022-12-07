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
        string str;
        cin>>str;
        int len=str.length();
        if(len==1){
            int k=str[0]-'0';
            if(k%4==0)cout<<4;
            else cout<<0;
        }
        else if(str[len-1]=='0'||str[len-1]=='4'||str[len-1]=='8'){
            if((str[len-2]-'0')&1)cout<<0;
            else cout<<4;
        }
        else if(str[len-1]=='2'||str[len-1]=='6'){
            if((str[len-2]-'0')&1)cout<<4;
            else cout<<0;
        }
        else{
            cout<<0;
        }
    //system("pause");
    return 0;
}