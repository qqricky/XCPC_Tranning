#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int gcd(int x,int y)
{
    return y ? gcd(y,x%y) : x;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)
    {
        int n;
        cin>>n;
        ll acu=1;
        vector<int>ans;
        ans.push_back(1);
        for(int i=2;i<n-1;i++){
            if(gcd(n,i)==1){
                acu=(acu*i)%n;
                ans.push_back(i);
            }
        }
        if(n>2&&acu*(n-1)%n==1)ans.push_back(n-1);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}