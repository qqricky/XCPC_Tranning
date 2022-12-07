#include <iostream>
#include <cstring>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int mp[150][150]={};
void floyd(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
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
    int n,m;
    while(cin>>n>>m)
    {
        int x,y;
        memset(mp,0x3f,sizeof(mp));
        for(int i=0;i<=n;i++)mp[i][i]=0;
        for(int i=1;i<=m;i++){
            cin>>x>>y;
            mp[x][y]=1;
            mp[y][x]=1;
        }
        floyd(n);
        int flag=1;
        if(m<n-1)flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(mp[i][j]>7){
                    flag=0;
                    break;
                }
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}