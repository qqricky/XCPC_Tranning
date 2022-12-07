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
    string str;
    while(cin>>str)
    {
        stack<int>s;
        int len=str.length();
        string tmp=str;
        str=' '+str;
        for(int i=1;i<=len;i++){
            if(str[i]=='('){
                s.push((i<<1)|1);
            }
            else if(str[i]==')'){
                if(!s.empty()&&(s.top()&1))s.pop();
                else s.push(i<<1);
            }
        }
        char ans[105];
        for(int i=1;i<=100;i++)ans[i]=' ';
        int maxx=0;
        while(!s.empty()){
            int x=s.top();
            //cout<<(x&1)<<'Q'<<(x>>1)<<endl;
            s.pop();
            if(x&1){
                maxx=max(maxx,x>>1);
                ans[x>>1]='$';
            }
            else{
                maxx=max(maxx,x>>1);
                ans[x>>1]='?';
            }
        }
        cout<<tmp<<endl;
        for(int i=1;i<=maxx;i++)cout<<ans[i];
        cout<<endl;
    }
    //system("pause");
    return 0;
}