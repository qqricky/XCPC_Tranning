#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
map<string,int>mp;
string s[1600];
string st="SET";
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    string tmp;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        s[i]=tmp;
        mp[tmp]++;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            string x;
            for(int g=0;g<k;g++){
                if(s[i][g]==s[j][g]){
                    x+=s[i][g];
                }
                else{
                    string ss;
                    ss+=s[i][g];
                    ss+=s[j][g];
                    //cout<<ss<<"aaa"<<endl;
                    x+=st[st.find_first_not_of(ss)];
                }
            }
            //cout<<i<<j<<x<<endl;
            if(mp[x])ans++;
        }
    }
    cout<<ans/3<<endl;
    //system("pause");
    return 0;
}