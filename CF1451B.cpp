#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int cnt[120];
string str;
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int len,q;
        cin>>len>>q;
        cin>>str;
        str=' '+str;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=len;i++){
            if(str[i]=='1'){
                cnt[i]=cnt[i-1]+1;
            }
            else{
                cnt[i]=cnt[i-1];
            }
        }
        int l,r;
        while(q--){
            cin>>l>>r;
            int flag=0;
            if(str[l]=='1'&&cnt[l-1]>0)flag=1;
            else if(str[l]=='0'&&cnt[l-1]<l-1)flag=1;
            if(str[r]=='1'&&cnt[len]-cnt[r]>0)flag=1;
            else if(str[r]=='0'&&cnt[len]-cnt[r]<len-r)flag=1;
            if(flag)cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    //cout.flush();
    //system("pause");
    return 0;
}