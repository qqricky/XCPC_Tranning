#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int isPal(string str)
{
    int len=str.length();
    str=' '+str;
    for(int i=1;i<=len/2;i++){
        if(str[i]!=str[len-i+1])return 0;
    }
    return 1;
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
        string str;
        cin>>str;
        int flag=1;
        for(int i=0;i<str.size();i++){
            if(str[i]!='a'){
                flag=0;
                break;
            }
        }
        if(flag)cout<<"NO"<<endl;
        else{
            string strr='a'+str;
            if(!isPal(strr)){
                cout<<"YES"<<endl<<strr<<endl;
            }
            else{
                string strrr=str+'a';
                cout<<"YES"<<endl<<strrr<<endl;
            }
        }
    }
    //system("pause");
    return 0;
}