#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int mp[105][105]={};
int ans[105][105]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ch;
    int n;
    cin>>ch>>n;
    int flag=1;
    string str;
    cin.get();
    for(int i=1;i<=n;i++){
        getline(cin,str);
        for(int j=0;j<str.length();j++){
            if(str[j]=='@')mp[i][j+1]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans[n-i+1][n-j+1]=mp[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mp[i][j]!=ans[i][j]){
                flag=0;
                break;
            }
        }
        if(flag==0)break;
    }
    if(flag)cout<<"bu yong dao le"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans[i][j]==1)cout<<ch;
            else cout<<' ';
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}