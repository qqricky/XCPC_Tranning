#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
map<char,int>mp;
int ck2(string str){
    stack<int>s;
    s.push(mp[str[0]]);
    if(s.top()==0)return 0;
    for(int i=1;i<str.length();i++){
        if(mp[str[i]]==1)s.push(1);
        else{
            if(s.empty())return 0;
            s.pop();
        }
    }
    return 1;
}
int ck(string str){
    mp.clear();
    int cnt[4]={};
    for(int i=0;i<str.length();i++)cnt[str[i]-'A'+1]++;
    if(cnt[1]==cnt[2]+cnt[3]){
        mp['A']=1;
        mp['B']=0;
        mp['C']=0;
        if(ck2(str))return 1;
        mp['A']=0;
        mp['B']=1;
        mp['C']=1;
        if(ck2(str))return 1;
    }
    if(cnt[2]==cnt[1]+cnt[3]){
        mp['B']=1;
        mp['A']=0;
        mp['C']=0;
        if(ck2(str))return 1;
        mp['B']=0;
        mp['A']=1;
        mp['C']=1;
        if(ck2(str))return 1;
    }
    if(cnt[3]==cnt[1]+cnt[2]){
        mp['C']=1;
        mp['A']=0;
        mp['B']=0;
        if(ck2(str))return 1;
        mp['C']=0;
        mp['A']=1;
        mp['B']=1;
        if(ck2(str))return 1;
    }
    return 0;
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(ck(str))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    //system("pause");
    return 0;
}