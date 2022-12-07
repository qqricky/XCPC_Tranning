#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int f[1070];
int get(int x)
{
    return x==f[x] ? x : f[x]=get(f[x]);
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n;
    while(n){
        cin>>m;
        for(int i=1;i<=n;i++)f[i]=i;
        int x,y;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            int a=get(f[x]);
            int b=get(f[y]);
            if(a<b){
                f[a]=b;
            }
            else if(a>b){
                f[b]=a;
            }
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            int z=get(i);
            if(z!=n){
                cnt++;
                f[z]=n;
            }
        }
        cout<<cnt<<endl;
        cin>>n;
    }
    //system("pause");
    return 0;
}