#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
string s;
int n;
struct  node
{
    int sum,len;
    node* fail,* ch[26];
    node(){}
}pat[N];
node * now;
int ncnt;
node *getfail(node * pre,int no)
{
    while(s[no - pre->len - 1]!=s[no]){
        //cout<<"now "<<no<<"pre->len "<<pre->len<<"ans "<<no-(pre->len)-1<<"---"<<endl;   
        pre = pre->fail; 
    }
    return pre;
}
int ans=0;
node* neww(int len)
{
    ncnt++;
    pat[ncnt].len=len;
    pat[ncnt].fail=&pat[2];//can dismiss it?
    for(int i=0;i<=25;i++)pat[ncnt].ch[i]=&pat[2];
    return &pat[ncnt];
}
void build()
{
    ncnt=2;
    pat[1].len=-1;
    pat[2].fail=&pat[1];
    pat[2].len=0;
    pat[1].fail=&pat[2];
    for(int i=0;i<=25;i++)pat[1].ch[i]=pat[2].ch[i]=&pat[2];
    now=&pat[2];
    int tt=1;
    //cout<<"L"<<getfail(&pat[2],1)->len;
    for(int i=1;i<=n;i++){
        if(i>1){
            s[i]=(s[i]-97+tt)%26+97;
        }
        //cout<<"www"<<now->len<<"///";
        node* cur=getfail(now,i);
        //cout<<"rrrr"<<cur->len<<endl;
        if(cur->ch[s[i]-'a']==&pat[2]){
            node * x=neww(cur->len+2);
            //cout<<i<<"WWW"<<cur->len<<endl;
            x->fail=getfail(cur->fail,i)->ch[s[i]-'a'];
            x->sum=x->fail->sum+1;
            cur->ch[s[i]-'a']=x;
        }
        now=cur->ch[s[i]-'a'];
        tt=now->sum;
        cout<<tt<<' ';
        //cout<<now->sum<<endl;
    }
    // int num=0;
    //         node *tmp=now;
    //         while(tmp->fail!=&pat[1]){
    //             //cout<<tmp->len<<endl;
    //             num++;
    //             tmp=tmp->fail;
    //         }
    //         cout<<num<<' ';
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    n=s.length();
    s=' '+s;
    //cout<<n<<endl;
    build();
    //cout.flush();
    //system("pause");
    return 0;
}