#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
struct node
{
    int fail;
    int ch[26]={};
    vector<int>end;
}ac[N];
int ncnt=0;
int cnt[N]={};
string str;
inline void build(string s,int num)
{
    int len=s.length();
    s=' '+s;
    int now=0;
    for(int i=1;i<=len;i++){
        if(ac[now].ch[s[i]-'a']==0){
            ac[now].ch[s[i]-'a']=++ncnt;
        }
        now=ac[now].ch[s[i]-'a'];
    }
    ac[now].end.push_back(num);
}
inline void constract()
{
    queue<int>q;
    for(int i=0;i<=25;i++){
        if(ac[0].ch[i]!=0){
            q.push(ac[0].ch[i]);
            ac[ac[0].ch[i]].fail=0;
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<=25;i++){
            int k=ac[u].ch[i];
            if(k){
                int tt=ac[ac[u].fail].ch[i];
                for(int j=0;j<ac[tt].end.size();j++){
                    ac[k].end.push_back(ac[tt].end[j]);
                }
                ac[k].fail=ac[ac[u].fail].ch[i];
                q.push(k);
            }
            else{
                ac[u].ch[i]=ac[ac[u].fail].ch[i];
            }
        }
    }
}
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
        cin>>str;
        build(str,i);
    }
    constract();
    cin>>str;
    int len=str.length();
    str=' '+str;
    int now=0;
    for(int i=1;i<=len;i++){
        now=ac[now].ch[str[i]-'a'];
        for(int j=0;j<ac[now].end.size();j++){
            cnt[ac[now].end[j]]++;
        }
    }
    int a[12];
    int b=3;
    {
        int t;
        int b=4;
        a[t=b]=1;
    }
    for(int i=1;i<=n;i++)cout<<cnt[i]<<"\n";
    //cout<<endl;
    //system("pause");
    return 0;
}