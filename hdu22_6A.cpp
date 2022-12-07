#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
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
int mm[N];
int dp[N][22];
int rmq(int x,int y){
    int k=mm[y-x+1];
    return min(dp[x][k],dp[y-(1<<k)+1][k]);
}
vector<int>ans;
multiset<pair<int,int> >s;
multiset<pair<int,int> >ss;
bool vis[N];
bool vi[N];
int main()
{
    // freopen("TestCase.in","r",stdin);
    // freopen("TestCase.in","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        ans.clear();
        ss.clear();
        memset(vis,0,sizeof(bool)*(n+2));
        memset(vi,0,sizeof(bool)*(n+2));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        s.clear();
        for(int i=1;i<=min(k+1,n);i++){
            s.insert(make_pair(-a[i],i));
        }
        int r=min(k+1,n);
        int ed=1;
        for(int i=1;i<=n;i++){
            if(k<=0){
                break;
            }
            if(vis[i]){
                continue;
            }
            while(r-i+1<k+1&& r<n){
                r++;
                s.insert(make_pair(-a[r],r));
            }
            auto pr=*s.begin();
            while(vi[pr.second]){
                s.erase(s.begin());
                pr=*s.begin();
            }
            // if(ss.size()){
            //     auto p=*ss.begin();
            //     if(-p.first>=-pr.first){
            //     }
            // }
            if(1){
                int pos=pr.second;
                if(pos<i)i--;
                ed=max(ed,pos+1);
                ans.push_back(-pr.first);
                s.erase(*s.begin());
                vis[pos]=1;
                vi[pos]=1;
                for(int j=i;j<pos;j++){
                    vis[j]=1;
                    ss.insert(make_pair(-a[j],j));
                    k--;
                }
            }else{
                ans.push_back(a[i]);
                s.erase(s.begin());
            }
        }
        int cnt=0;
        for(int x:ans){
            cnt++;
            cout<<x;
            if(cnt<n)cout<<' ';
        }
        for(int i=ed;i<=n;i++){
            if(ss.size()){
                auto pr=*ss.begin();
                while(ss.size()&&vi[pr.second]){
                    ss.erase(ss.begin());
                    if(ss.size())pr=*ss.begin();
                }
            }
            if(ss.size()){
                auto pr=*ss.begin();
                if(-pr.first>a[i]){
                    i--;
                    cnt++;
                    cout<<-pr.first;
                    if(cnt<n)cout<<' ';
                    ss.erase(ss.begin());
                }else{
                    cnt++;
                    cout<<a[i];
                    if(cnt<n)cout<<' ';
                }
            }else{
                cnt++;
                cout<<a[i];
                if(cnt<n)cout<<' ';
            }
        }
        for(auto pr:ss){
            if(!vi[pr.second]){
                cnt++;
                cout<<-pr.first;
                if(cnt<n)cout<<' ';
            }
        }
        cout<<'\n';
        // mm[0]=-1;
        // for(int i=1;i<=n;i++){
        //     mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
        //     dp[i][0]=a[i];
        // }
        // for(int j=1;j<=mm[n];j++){
        //     for(int i=1;i+(1<<j)-1<=n;i++){
        //         dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
        //     }
        // }
    }
    // std::cout.flush();
    // std::system("pause");
    return 0;
}