#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int gcd(int a,int b)
{
    return b? gcd(b,a%b):a;
}
int a[N];
int ne[N];
vector<int>ans;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    queue<pair<int,int> >q;
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int n;
        cin>>n;
        a[0]=0;
        for(int i=1;i<=n;i++){ne[i]=i+1;}
        ne[n]=1;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            if(gcd(a[i],a[i+1])==1){
                q.push(make_pair(i,i+1));
                //cout<<i<<' '<<i+1<<endl;
                i++;
            }
        }
        if(gcd(a[n],a[1])==1){
            q.push(make_pair(n,1));
        }
        while(q.size())
        {
            pair<int,int>p=q.front();
            q.pop();
            if(ne[p.first]==0)continue;
            //cout<<p.first<<' '<<p.second<<endl;
            ans.push_back((p.second));
            ne[p.first]=ne[p.second];
            ne[p.second]=0;
            if(gcd(a[p.first],a[ne[p.first]])==1){
                q.push(make_pair(p.first,ne[p.first]));
            }
        }
        if(n-ans.size()==1){
            for(int i=1;i<=n;i++){
                if(ne[i]){
                    if(a[i]==1)ans.push_back(1);
                    else break;
                }
            }
        }
        cout<<ans.size()<<' ';
        for(auto it=ans.begin();it!=ans.end();it++){
            cout<<*it<<' ';
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
} 