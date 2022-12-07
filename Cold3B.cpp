#include <bits/stdc++.h>
#define ll long long
const int N=1e4+10; 
using namespace std;
int v[25];
int pre [N];
int f[N];
void put(int x)
{
    if(x<=0)return;
    put(x-v[pre[x]]);
    cout<<v[pre[x]]<<' ';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m)
    {
        //memset(pre,0,sizeof(pre));
        memset(f,0,sizeof(f));
        f[0]=1;
        for(int i=1;i<=m;i++)cin>>v[i];
        for(int i=1;i<=m;i++){
            for(int j=n;j>=v[i];j--){
                if(f[j-v[i]]&&!f[j]){
                    f[j]=1;
                    pre[j]=i;
                    if(j==n)goto paris;
                }
            }
        }
        paris:;
        int maxx;
        for(int i=n;i>=0;i--){
            if(f[i]){
                maxx=i;
                break;
            }
        }
        put(maxx);
        cout<<"sum:"<<maxx<<endl;
    }
    //system("pause");
    return 0;
}