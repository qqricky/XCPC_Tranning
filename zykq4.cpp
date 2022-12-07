#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
int q1[N],q2[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    // ios_base::sync_with_stdio(false); 
    // cin.tie(0);
    // cout.tie(0);
    int n,m;
    cin>>n>>m;
    int st1=0,st2=0;
    int ed1=0,ed2=0;
    for(int i=1;i<=n;i++){
        cin>>q1[++ed1];
    }
    for(int i=1;i<=m;i++){
        cin>>q2[++ed2];
    }
    for(int t=1;t<=max(ed1,ed2);t++){
        cout<<"Round "<<t<<endl;
        cout<<"BoyNo."<<q1[++st1]<<" fight with GirlNo."<<q2[++st2]<<endl;
        if(st1==ed1)st1=0;
        else if(st2==ed2)st2=0;
    }
    //system("pause");
    return 0;
}