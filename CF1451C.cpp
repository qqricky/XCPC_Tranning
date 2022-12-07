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
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string str1,str2;
        cin>>str1>>str2;
        int flag=1;
        int cnt1[28]={};
        int cnt[28]={};
        for(int i=0;i<n;i++){
            cnt1[str1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            cnt[str2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]&&cnt1[i]){
                int kk=min(cnt[i],cnt1[i]);
                cnt[i]-=kk;
                cnt1[i]-=kk;
            }
        }
        vector<char>v1;
        vector<char>v2;
        for(int i=0;i<26;i++){
            if(cnt[i]%k!=0){
                //cout<<char(i+'a')<<cnt[i]<<"aaaaaaa"<<endl;
                flag=0;
                break;
            }
            for(int j=1;j<=cnt[i]/k;j++){
                v2.push_back((char)(i+'a'));
            }
        }
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        for(int i=0;i<26;i++){
            if(cnt1[i]%k!=0){
                flag=0;
                break;
            }
            for(int j=1;j<=cnt1[i]/k;j++){
                v1.push_back((char)(i+'a'));
            }
        }
        if(v1.size()!=v2.size())flag=0;
        if(!flag){
            cout<<"No"<<endl;
            continue;
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                flag=0;break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    //system("pause");
    return 0;
}