#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
string s[100];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int n,m;
    while(t--)
    {
        cin>>n>>m;
        string str;
        char ans[12]={};
        cin>>s[1];
        int flag=1;
        if(n==1){
            cout<<s[1]<<endl;
            continue;
        }
        cin>>s[2];
        int cnt=0;
        int pos[3]={};
        for(int j=0;j<m;j++){
            if(s[2][j]!=s[1][j]){
                cnt++;
                if(cnt>2){
                    flag=0;
                    break;
                }
                ans[j]='!';
            }
        }
        if(!flag){
            cout<<-1<<endl;
            break;
        }
        for(int i=0;i<m;i++){
            if(ans[i]!='!')ans[i]=s[1][i];
        }
        for(int i=3;i<=n;i++){
            cin>>s[i];
            int cnt=0;
            for(int j=0;j<m;j++){
                if(s[i][j]!=ans[j])cnt++;
            }
        }
    }
    //system("pause");
    return 0;
}