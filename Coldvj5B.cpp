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
    int m;
    cin>>m;
    while(m--)
    {
        int n;
        cin>>n;
        stack<int>s;
        queue<int>q;
        string str;
        int flag=1;
        for(int i=1;i<=n;i++){
            cin>>str;
            if(str=="push"){
                int tmp;
                cin>>tmp;
                q.push(tmp);
                s.push(tmp);
            }
            else{
                if(s.empty()){
                    flag=0;
                }
                else{
                    s.pop();
                    q.pop();
                }
            }
        }
        if(!flag){
            cout<<"error\n"<<"error"<<endl;
            continue;
        }
        if(q.empty()){
            cout<<endl<<endl;
            continue;
        }
        while(q.size()>1){
            cout<<q.front()<<' ';
            q.pop();
        }
        if(q.size())
        cout<<q.front()<<endl;
        vector<int>v;
        while(s.size()){
            v.push_back(s.top());
            s.pop();
        }
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i];
            if(i)cout<<' ';
        }
        if(q.size())
        cout<<endl;
    }
    //system("pause");
    return 0;
}