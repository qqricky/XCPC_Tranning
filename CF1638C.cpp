#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
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
    while(t--){
        priority_queue<int,vector<int> >q;
        int n;
        cin>>n;
        int x;
        cin>>x;
        q.push(x);
        for(int i=2;i<=n;i++){
            cin>>x;
            if(x>q.top()){
                q.push(x);
                continue;
            }
            int y=q.top();
            q.pop();
            while(!q.empty()&&q.top()>x){
                q.pop();
            }
            q.push(y);
        }
        cout<<q.size()<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}