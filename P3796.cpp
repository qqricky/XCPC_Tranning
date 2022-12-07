#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=20000; 
using namespace std;
struct node
{
    int fail;
    int ch[26]={};
    int end;
}ac[N];
int ncnt=0;
int cnt[160]={};
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
    ac[now].end=num;
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
        //cout<<u<<endl;
        for(int i=0;i<=25;i++){
            int k=ac[u].ch[i];
            if(k){
                ac[k].fail=ac[ac[u].fail].ch[i];
                q.push(k);
                //cout<<k<<endl;
            }
            else{
                ac[u].ch[i]=ac[ac[u].fail].ch[i];
            }
        }
    }
}
void clear(int num)
{
    for(int i=0;i<=num;i++){
        ac[i].end=0;
        memset(ac[i].ch,0,sizeof(ac[i].ch));
        ac[i].fail=0;
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
    while(1){
        ncnt=0;
        cin>>n;
        string log[161];
        if(!n)break;
        for(int i=1;i<=n;i++){
            cin>>str;
            log[i]=str;
            build(str,i);
        }
        constract();
        cin>>str;
        int len=str.length();
        str=' '+str;
        int now=0;
        int ma=0;
        for(int i=1;i<=len;i++){
            now=ac[now].ch[str[i]-'a'];
            for(int t=now;t;t=ac[t].fail){
                //cout<<t<<endl;
                //cout<<ac[t].end<<endl;
                cnt[ac[t].end]++;
                if(ac[t].end>0)
                ma=max(ma,cnt[ac[t].end]);
            }
        }
        cout<<ma<<"\n";
        for(int i=1;i<=n;i++){
            if(cnt[i]==ma){
                cout<<log[i]<<"\n";
            }
        }
        memset(cnt,0,sizeof(cnt));
        clear(ncnt);
        cout.flush();
        //cout<<endl;
        //system("pause");
    }
    //system("pause");
    return 0;
}