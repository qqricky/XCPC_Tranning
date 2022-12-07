#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
int cnt[20020][27]={};
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
        int l,d;
        cin>>l>>d;
        string str1;
        string str2;
        cin>>str1>>str2;
        memset(cnt,0,sizeof(int)*27*(l+1));
        int flag=0;
        for(int i=0;i<l;i++){
            cnt[i%d][str1[i]-'a']++;
            if(cnt[i%d][str1[i]-'a']==1)flag++;
        }
        for(int i=0;i<l;i++){
            cnt[i%d][str2[i]-'a']--;
            if(cnt[i%d][str2[i]-'a']==0)flag--;
        }
        if(flag)cout<<"No\n";
        else cout<<"Yes\n";
    }
    //cout.flush();
    //system("pause");
    return 0;
}