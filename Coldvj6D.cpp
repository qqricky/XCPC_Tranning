#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
int mp[404][404];
ll a[N];
int d=INF;
int m[404][404];
void flyod(int cs)
{
    for(int k=1;k<=cs;k++){
        for(int i=1;i<=cs;i++){
            for(int j=1;j<=cs;j++){
                if(i!=j){
                    d=min(d,mp[i][j]+m[i][k]+m[k][j]);
                    //cout<<d<<'Q'<<i<<'w'<<j<<'w'<<k<<'w'<<endl;
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
                }
            }
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
    int n;
    cin>>n;
    int pos=0;
    ll tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        if(tmp){
            a[++pos]=tmp;
        }
    }
    if(pos>126){
        cout<<3;
    }
    else{
        for(int i=1;i<=pos;i++){
            for(int j=1;j<=pos;j++)mp[i][j]=114514,m[i][j]=114514;
        }
        for(int i=1;i<=pos;i++){
            for(int j=1;j<i;j++){
                if(a[i]&a[j]){
                    //cout<<i<<'-'<<j<<"\n";
                    mp[i][j]=mp[j][i]=1;
                    m[i][j]=m[j][i]=1;
                }
            }
        }
        flyod(pos);
        if(d>n)cout<<-1;
        else cout<<d;
    }
    //system("pause");
    return 0;
}