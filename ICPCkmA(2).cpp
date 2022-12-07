#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=5e5+10; 
using namespace std;
char a[N];
int v[N]={};
int c[N]={};
int rt[N];
int lf[N];
int l[N];
int r[N];
int num[N]={};
int mark[N]={};
struct node
{
    int val;
    int pos;
}t;
bool operator < (const node &x,const node &y)
{
    return x.val>y.val;
}
void change(int pos,int num)
{
    if(num&1){
        for(int i=1;i<=num;i+=2){
            a[pos-(i-1)]='a';
            a[pos-(i-1)+1]='c';
            a[pos+i-1]='a';
            a[pos+i]='c';
        }
    }
    else{
        for(int i=2;i<=num;i+=2){
            a[pos-(i-1)]='a';
            a[pos-(i-1)+1]='c';
            a[pos+i-1]='a';
            a[pos+i]='c';
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
    int n,k;
    priority_queue<node>q;
    map<int,int>mp; 
    cin>>n>>k;
    r[0]=l[0]=0;
    //lf[n]=n-1;
    //rt[n]=n+1;
    //rt[0]=1;
    //lf[n+1]=n;
    c[0]=c[n]=INF;
    for(int i=1;i<=n;i++){cin>>a[i];l[i]=i,r[i]=i;}
    for(int i=1;i<n;i++){
        rt[i]=i+1;
        lf[i]=i-1;
        if(a[i]!='a')c[i]++;
        if(a[i+1]!='c')c[i]++;
        q.push((node){c[i],i});
    }
    int cnt=0;
    while(!q.empty())
    {
        while(!q.empty()&&v[q.top().pos])q.pop();
        if(q.empty())break;
        t=q.top();
        q.pop();
        if(t.val>k){
            break;
        }
        cnt++;
        mp[t.pos]=1;
        k-=t.val;
        c[t.pos]=c[lf[t.pos]]+c[rt[t.pos]]-c[t.pos];
        q.push((node){c[t.pos],t.pos}); 
        v[rt[t.pos]]=1;
        v[lf[t.pos]]=1;
        l[t.pos]=l[lf[t.pos]];
        r[t.pos]=r[rt[t.pos]];
        lf[t.pos]=lf[lf[t.pos]];
        rt[t.pos]=rt[rt[t.pos]];
        rt[lf[t.pos]]=t.pos;
        lf[rt[t.pos]]=t.pos;
    }
    for(int i=1;i<n;i++){
        if(mp[i]&&!v[i]){
            for(int j=l[i]+1;j+1<=r[i]&&j+1<=n;j+=2){
                a[j]='a';
                a[j+1]='c';
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)cout<<a[i];
    cout.flush();
    //system("pause");
    return 0;
}