#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10;
using namespace std;
char mp[303][303];
int a[303];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mp[i][j];
        }
    }
    int pos=0;
    vector<int>v[303];
    int num[303]={};
    int ver[303]={};
    int vi[303]={};
    for(int i=1;i<=n;i++){
        if(!vi[i]){
            vi[i]=1;
            ver[i]=++pos;
            v[pos].push_back(a[i]);
            for(int j=i+1;j<=n;j++){
                if(mp[i][j]=='1'){
                    vi[j]=1;
                    ver[j]=pos;
                    v[pos].push_back(a[j]);
                }
            }
        }
    }
    for(int i=1;i<=pos;i++)sort(v[i].begin(),v[i].end());
    for(int i=1;i<n;i++){
        cout<<v[ver[i]][num[ver[i]]++]<<' ';
    }
    cout<<v[ver[n]][num[ver[n]]++];
    cout.flush();
    system("pause");
    return 0;
}