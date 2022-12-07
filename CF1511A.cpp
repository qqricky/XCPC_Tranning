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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=0;
        int y=0;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            if(tmp==1||tmp==3)x++;
            else y++;
        }
        cout<<x<<endl;
    }
    //system("pause");
    return 0;
}