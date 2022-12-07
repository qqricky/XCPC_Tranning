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
    int n;
    string str;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>str;
        int cnt=0;
        int cnt2=0;
        for(int i=0;i<n-1;i++){
            if(str[i]=='1'&&str[i+1]=='1')cnt++;
            if(str[i]=='0'&&str[i+1]=='0')cnt2++;
        }
        cout<<max(cnt,cnt2)<<endl;
    }
    //system("pause");
    return 0;
}