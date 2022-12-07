#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
char mp[100][100];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r,c;
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>mp[i][j];
        }
    }
    int flag=1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mp[i][j]=='W'){
                if(mp[i][j+1]=='P'||mp[i+1][j]=='P'||mp[i-1][j]=='P'||mp[i][j-1]=='P'){
                    flag=0;
                    break;
                }
            }
        }
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
    //cout.flush();
    //system("pause");
    return 0;
}