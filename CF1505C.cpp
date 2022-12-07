#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
set<int>s;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int flag=1;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(8);
    s.insert(13);
    s.insert(21);
    s.insert(34);
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(s.count(str[i]-'A'+1)==0)flag=0;
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
    cout.flush();
    system("pause");
    return 0;
}