#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=2e5+10; 
using namespace std;
int ncnt=1;
struct node
{
    node* ch[26];
    node* fail;
    node*pre;
    char pc;
    vector<int>v;
}act[N];
int cnt[N]={};
node* neww()
{
    ncnt++;
    for(int i=0;i<=25;i++)act[ncnt].ch[i]=&act[1];
    return &act[ncnt];
}
void build()
{
    node*now=&act[1];
    queue<node*>q;
    for(int i=0;i<=25;i++){
        if(act[1].ch[i]!=&act[1]){
            act[1].ch[i]->fail=&act[1];
            for(int j=0;j<=25;j++){
                if(act[1].ch[i]->ch[j]!=&act[1]){
                    q.push(act[1].ch[i]->ch[j]);
                }
            }
        }
    }
    while(q.size())
    {
        node*x=q.front();
        q.pop();
        x->fail=x->pre->fail->ch[(x->pc)-'a'];
        if(x->fail!=x)
        for(int j=0;j<(x->fail->v).size();j++){
            x->v.push_back(x->fail->v[j]);
        }
        for(int i=0;i<=25;i++){
            if(x->ch[i]!=&act[1]){
                q.push(x->ch[i]);
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
    string str;
    cin>>n;
    act[1].fail=&act[1];
    for(int i=0;i<=25;i++)act[1].ch[i]=&act[1];
    for(int i=1;i<=n;i++){
        cin>>str;
        int len=str.length();
        str=' '+str;
        node* now=&act[1];
        for(int j=1;j<=len;j++){
            if(now->ch[str[j]-'a']==&act[1]){
                node*x;
                x=neww();
                x->pc=str[j];
                x->pre=now;
                now->ch[str[j]-'a']=x;
                now=x;
            }
            else{
                node* x=now->ch[str[j]-'a'];
                now=x;
            }
            if(j==len){
                //cout<<i<<endl;
                now->v.push_back(i);
            }
        }
    }
    build();
    cin>>str;
    node* last=&act[1];
    int len=str.length();
    str=' '+str+'!';
    map<node*,int>mp;
     for(int i=1;i<=ncnt;i++){
         //cout<<i<<"   "<<&act[i]<<endl;
         mp[&act[i]]=i;
     }
    //  for(int i=1;i<=9;i++){
    //      cout<<i<<"  :  "<<mp[act[i].fail]<<endl;
    //  }
    for(int i=1;i<=len+1;i++){
        //cout<<last<<endl;
        //cout<<i<<"  :  "<<mp[last]<<endl;
        if(last!=&act[1]){
            for(int j=0;j<last->v.size();j++){
                cnt[last->v[j]]++;
            }
        }
        if(last->ch[str[i]-'a']!=&act[1]){
            last=last->ch[str[i]-'a'];
        }
        else{
            while(last->ch[str[i]-'a']==&act[1]){
                last=last->fail;
                //cout<<last<<endl;
                if(last==&act[1])break;
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<cnt[i]<<"\n";
    cout<<endl;
    system("pause");
    return 0;
}