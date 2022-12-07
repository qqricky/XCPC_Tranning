#include <bits/stdc++.h>
#include <map>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
struct node
{
    int fail;
    int ch[26]={};
    int end;
    int ans;
}ac[N];
int ind[N]={};
int ncnt=0;
int cnt[N]={};
int mp[N]={};
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
    if(!ac[now].end){
        ac[now].end=num;
    }
    mp[num]=ac[now].end;

}
inline void constract()
{
    queue<int>q;
    for(int i=0;i<=25;i++){
        if(ac[0].ch[i]!=0){
            q.push(ac[0].ch[i]);
            ac[ac[0].ch[i]].fail=0;
            ind[0]++;
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
                ind[ac[ac[u].fail].ch[i]]++;
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
        mp[i]++;
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
            ac[now].ans++;
    }
    queue<int>q;
    for(int i=1;i<=ncnt;i++)if(ind[i]==0){
        q.push(i);
        cnt[ac[i].end]+=ac[i].ans;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        ind[ac[u].fail]--;
        ac[ac[u].fail].ans+=ac[u].ans;
        if(ind[ac[u].fail]==0){
            cnt[ac[ac[u].fail].end]=ac[ac[u].fail].ans;
            q.push(ac[u].fail);
        }
    }
    for(int i=1;i<=n;i++)cout<<cnt[mp[i]]<<"\n";
    //cout<<endl;
    //system("pause");
    return 0;
}