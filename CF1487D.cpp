#include <bits/stdc++.h>
#define ll long long
const ll N=1e9; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    //for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
    while(t--)
    {
        ll n;
        cin>>n;
        int cnt=0;
        int pos=0;
        int k=sqrt(2*n-1);
        cnt=k/2-1+(k&1);
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}