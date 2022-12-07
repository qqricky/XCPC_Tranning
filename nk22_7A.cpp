#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
int read()
{
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return f*x;
}
int a[N];
struct node
{
    int val,num;
    bool operator<(const node &b)const{
        if(num==b.num){
            return val>b.val;
        }
        return num<b.num;
    }
};
int num[N];
stack<int>pos[N];
int ans[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            while(pos[i].size())pos[i].pop();
            num[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            num[a[i]]++;
            pos[a[i]].push(i);
        }
        priority_queue<node>q;
        for(int i=1;i<=n;i++){
            if(num[i]){
                q.push((node){i,num[i]});
            }
        }
        bool flag=0;
        for(int i=1;i<=n;i++){
            node x=q.top();
            q.pop();
            if(x.num==0){
                flag=0;
                break;
            }
            if(x.val!=i){
                int tmp=pos[x.val].top();
                pos[x.val].pop()
            }else{

            }
        }
    }
    // cout.flush();
    // system("pause");
    return 0;
}