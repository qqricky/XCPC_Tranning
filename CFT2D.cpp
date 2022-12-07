#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+10;
using namespace std;
bool check[N];
int p[N/10];
void init()
{
    ll t;
    for(int i=2;i<=N;i++){
        if(!check[i]){
            p[++p[0]]=i;
        }
        for(int j=1;j<=p[0];j++){
            t=i*p[j];
            if(t>N)break;
            check[t]=true;
            if(i%p[j]==0)break;
        }
    }
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
    p[0]=0;
    check[1]=1;
    init();
    while(t--)
    {
        int k;
        cin>>k;
        vector<int>ans;
        for(int i=2;p[i]<=k+2;i++){
            if((k+2)%p[i]==0){
                ans.push_back(p[i]);
            }
        }
        if(ans.empty())cout<<"-1";
        else{
            for(int i=0;i<ans.size()-1;i++){
                    cout<<ans[i]<<' ';
            }
            cout<<ans[ans.size()-1];
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}