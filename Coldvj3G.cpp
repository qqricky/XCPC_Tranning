#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int a[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin>>n)
    {
        vector<int>ans;
        cin>>a[1];
        ans.push_back(a[1]);
        for(int i=2;i<=n;i++){
            cin>>a[i];
            if(a[i]>ans[ans.size()-1])ans.push_back(a[i]);
            else{
                int k=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[k]=a[i];
            }
        }
        cout<<ans.size()<<endl;
    }
    //system("pause");
    return 0;
}