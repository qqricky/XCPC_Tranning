#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
// struct  node
// {
//     int sum,len;
//     node* fail,* ch[26];
//     node(){}
// }pat[N];
int n,m;
int a[2*N];
int p[N]={};
string str;
char s[2*N];
int len,len2;
void init(){
    memset(a,0,sizeof(int)*(n+2));
    //memset(p,0,sizeof(p));
    s[0]=s[1]='#';
    for(int i=1;i<=len;i++){
        s[i*2]=str[i];
        s[i*2+1]='#';
    }
    len2=len*2+1;
}
void manacher(){
    int mid=0,mr=0;
    for(int i=1;i<=len2;i++){
        if(mr>i)a[i]=min(a[2*mid-i],mr-i);
        else a[i]=1;
        while(s[i+a[i]]==s[i-a[i]])a[i]++;
        if(a[i]+i>mr){
            mr=a[i]+i;
            mid=i;
        }
    }
}
vector<int>light[N];
void add(int pos,int val){
    for(int i=pos;i<=n;i+=(i&-i)){
        p[i]+=val;
    }
}
ll ask(int pos){
    ll sum=0;
    for(int i=pos;i;i-=(i&-i)){
        sum+=p[i];
    }
    return sum;
}
ll range_ask(int l,int r){
    if(l>r)return 0;
    return ask(r)-ask(l-1);
}
// node *getfail(node * pre,int no)
// {
//     while(s[no - pre->len - 1]!=s[no]){
//         //cout<<"now "<<no<<"pre->len "<<pre->len<<"ans "<<no-(pre->len)-1<<"---"<<endl;   
//         pre = pre->fail; 
//     }
//     return pre;
// }
// int ans=0;
// node* neww(int len)
// {
//     ncnt++;
//     pat[ncnt].len=len;
//     pat[ncnt].fail=&pat[2];//can dismiss it?
//     for(int i=0;i<=25;i++)pat[ncnt].ch[i]=&pat[2];
//     return &pat[ncnt];
// }
// void build()
// {
//     ncnt=2;
//     pat[1].len=-1;
//     pat[2].fail=&pat[1];
//     pat[2].len=0;
//     pat[1].fail=&pat[2];
//     for(int i=0;i<=25;i++)pat[1].ch[i]=pat[2].ch[i]=&pat[2];
//     now=&pat[2];
//     //cout<<"L"<<getfail(&pat[2],1)->len;
//     for(int i=1;i<=n;i++){
//         //cout<<"www"<<now->len<<"///";
//         node* cur=getfail(now,i);
//         //cout<<"rrrr"<<cur->len<<endl;
//         if(cur->ch[s[i]-'a']==&pat[2]){
//             node * x=neww(cur->len+2);
//             //cout<<i<<"WWW"<<cur->len<<endl;
//             x->fail=getfail(cur->fail,i)->ch[s[i]-'a'];
//             cur->ch[s[i]-'a']=x;
//         }
//         now=cur->ch[s[i]-'a'];
//         a[i]=now->len;
//         //cout<<now->sum<<endl;
//     }
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
    	cin>>str;
        n=str.length();
        len=str.size();
        str=' '+str;
        init();
        manacher();
        ll ans=0;
        for(int i=1;i<=n;i++){
            a[i]=a[2*i]/2;
        }
        for(int i=n;i>=1;i--){
            for(int j=0;j<light[i].size();j++){
                add(light[i][j],-1);
            }
            light[i].clear();
            int tmp=a[i];
            ans+=range_ask(i+1,min(n,i+tmp-1));
            if(tmp==1)continue;
            add(i,1);
            light[max(i-tmp,0)].push_back(i);
        }
        for(int j=0;j<light[0].size();j++){
                add(light[0][j],-1);
            }
        //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
        cout<<ans<<'\n';
    }
    cout.flush();
    //system("pause");
    return 0;
}