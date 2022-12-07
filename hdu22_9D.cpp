#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#pragma GCC optimise(3)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int a[N];
unordered_map<int,int>to;
// bool cmp(node a,node b){
//     return a.x<b.x;
// }
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        to.clear();
        int n;
        cin>>n;
        bool flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            to[a[i]]=i;
        }
        // sort(nd+1,nd+n+1);
        if(!flag){
            cout<<"NO\n";
            continue;
        }
        sort(a+1,a+n+1);
        a[n+1]=INF;
        // bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
                flag=0;
                break;
            }
            for(int j=i+1;j<=n;j++){
                int val=2*a[j]-a[i];
                int pos=to[val];
                if(pos>j){
                    swap(a[i],a[j]);
                }
            }
        }
        if(flag){
            cout<<"YES\n";
            for(int i=1;i<=n;i++)cout<<a[i]<<' ';
            cout<<'\n';
        }else{
            cout<<"NO\n";
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}