#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll n=1e5+10;
stack<char>s[120];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,ss;
    cin>>n>>m>>ss;
    string ans;
    string str;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=m-1;j>=0;j--){
            s[i].push(str[j]);
        }
    }
    int val;
    stack<char>b;
    cin>>val;
    while(val!=-1){
        if(val){
            if(s[val].empty())goto end;
            if(b.size()>=ss){
                ans+=b.top();
                b.pop();
                b.push(s[val].top());
                s[val].pop();
            }
            else{
                b.push(s[val].top());
                s[val].pop();
            }
        }
        else{
            if(b.empty())goto end;
            ans+=b.top();
            b.pop();
        }
        end:;
        cin>>val;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}