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
    int n,m,d,u,v,t;
    cin>>n>>m>>d>>u>>v>>t;
    vector<int>ans;
    ans.push_back(0);
    priority_queue<int>q;
    double p=(double)u/(double)v;
    int x;
    for(int i=1;i<=n;i++){
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=m;i++){
        x=q.top();
        q.pop();
        x+=(i-1)*d;
        //cout<<x<<endl;
        ans.push_back(x);
        q.push(floor(p*x)-(i)*d);
        //cout<<floor(p*x)-(i-1)*d<<'Q';
        q.push(x-floor(p*x)-(i)*d);
        //cout<<x-floor(p*x)-(i-1)*d<<endl;
    }
    for(int i=t;i<=m;i+=t){
        cout<<ans[i]<<' ';
    }
    cout<<"\n";
    int cnt=0;
    while(q.size()){
        x=q.top();
        q.pop();
        cnt++;
        if(cnt%t==0){
            cout<<x+m*d<<' ';
        }
    }
    cout<<"\n";
    //system("pause");
    return 0;
}