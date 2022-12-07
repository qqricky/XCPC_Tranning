#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int h[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n)
    {
        for(int i=1;i<=n;i++)cin>>h[i];
        stack<ll>w;
        stack<ll>s;
        w.push(1);
        s.push(h[1]);
        ll ans=h[1];
        for(int i=2;i<=n;i++){
            if(s.top()>=h[i]){
                ll x=0;
                while(!s.empty()&&s.top()>=h[i]){
                    x+=w.top();
                    ans=max(ans,x*s.top());
                    s.pop();
                    w.pop();
                }
                w.push(x+1);
                s.push(h[i]);
            }
            else{
                w.push(1);
                s.push(h[i]);
            }
        }
        ll len=0;
        while(s.size())
        {
            len+=w.top();
            ans=max(ans,len*s.top());
            s.pop();
            w.pop();
        }
        cout<<ans<<endl;
        cin>>n;
    }
    //system("pause");
    return 0;
}