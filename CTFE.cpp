#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;

int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string str;
    cin>>str;
    str=' '+str+'@';
    int cnt=1;
    string x="RGB";
    ll ans=0;
    for(int i=1;i<=n+1;i++){
        if(str[i]==str[i-1]){
            cnt++;
        }
        else{
            if(cnt>1){
                ans+=cnt/2;
                if(cnt&1){
                for(int j=i-2;j>=(i-cnt);j-=2){
                    string tt;
                    tt=str.substr(j-1,1)+str.substr(j+1,1);
                    // cout<<x[x.find_first_not_of(tt)]<<endl;
                    //cout<<tt<<endl;
                    str[j]=x[x.find_first_not_of(tt)];
                }
                }
                else{
                for(int j=i-1;j>=(i-cnt);j-=2){
                    string tt;
                    tt=str.substr(j-1,1)+str.substr(j+1,1);
                    str[j]=x[x.find_first_not_of(tt)];
                }
                }
                cnt=1;
            }
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)cout<<str[i];
    cout<<endl;
    //system("pause");
    return 0;
}