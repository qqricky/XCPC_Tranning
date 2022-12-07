#include <bits/stdc++.h>
#define ll long long
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    cin>>str;
    int val=0;
    for(int i=0;i<str.length();i++){
        val=(val*10-+str[i]-'0')%4;
    }
    if(val==0)cout<<4;
    else cout<<0;

    //system("pause");
    return 0;
}