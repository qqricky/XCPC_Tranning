#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=2e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}int a[N];
set<int>s1;
set<int>s2;
int rmx[N];
int rmn[N];
int lmx[N];
int lmn[N];
bool vis[N];
int pos[N];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(vis,0,sizeof(bool)*(n+5));
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=i;
        }
        if(n==1){
            cout<<0<<'\n';
            continue;
        }
        for(int i=n;i>=1;i--){
            auto it=s1.upper_bound(a[i]);
            if(it==s1.end())rmx[i]=n+1;
            else rmx[i]=pos[*it];
            auto it2=s2.upper_bound(a[i]);
            if(it2==s2.begin())rmn[i]=n+1;
            else{
                it2--;
                rmn[i]=pos[*it2];
            }
            // auto p=s1.end();
            // if(s1.size())p--;
            // while(s1.size()&&a[i]>(*p)){
            //     s1.erase(p);
            //     p=s1.end();
            //     if(s1.size())p--;
            // }
            while(s1.size()&&a[i]>*s1.begin())s1.erase(s1.begin());
            while(s2.size()&&a[i]<*s2.begin())s2.erase(s2.begin());
            s1.insert(a[i]);
            s2.insert(a[i]);
            // cout<<i<<' '<<rmx[i]<<' '<<rmn[i]<<'\n';
        }
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;i++){
            auto it=s1.upper_bound(a[i]);
            if(it==s1.end())lmx[i]=n+1;
            else lmx[i]=pos[*it];
            auto it2=s2.upper_bound(a[i]);
            if(it2==s2.begin())lmn[i]=n+1;
            else{
                it2--;
                lmn[i]=pos[*it2];
            }
            auto p=s1.end();
            if(s1.size())p--;
            while(s1.size()&&a[i]>*p){
                s1.erase(p);
                p=s1.end();
                if(s1.size())p--;
            }
            while(a[i]<*s2.begin())s2.erase(s2.begin());
            s1.insert(a[i]);
            s2.insert(a[i]);
        }
        queue<pair<int,int> >q;
        q.push(make_pair(1,0));
        vis[1]=1;
        while(!q.empty()){
            auto pr=q.front();
            q.pop();
            // cout<<pr.first<<' '<<pr.second<<'\n';
            if(pr.first==n){
                cout<<pr.second<<'\n';
                break;
            }
            int now=pr.first;
            int mx=rmx[now];
            int mn=rmn[now];
            // cout<<"---------- "<<mx<<' '<<mn<<'\n';
            if(mn<mx){
                now=rmn[now];
                while(now<mx){
                    if(!vis[now]){
                        q.push(make_pair(now,pr.second+1));
                        vis[now]=1;
                    }else{
                        break;
                    }
                    now=rmn[now];
                }
            }else{
                now=rmx[now];
                while(now<mn){
                    if(!vis[now]){
                        q.push(make_pair(now,pr.second+1));
                        vis[now]=1;
                    }else{
                        break;
                    }
                    now=rmx[now];
                }
            }
            mx=lmx[now];
            mn=lmn[now];
            // cout<<"---------- "<<mx<<' '<<mn<<'\n';
            if(mn>mx){
                now=lmn[now];
                while(now<mx){
                    if(!vis[now]){
                        q.push(make_pair(now,pr.second+1));
                        vis[now]=1;
                    }
                    now=lmn[now];
                }
            }else{
                now=lmx[now];
                while(now<mn){
                    if(!vis[now]){
                        q.push(make_pair(now,pr.second+1));
                        vis[now]=1;
                    }
                    now=lmx[now];
                }
            }
        }
    }   
    cout.flush();
    // system("pause");
    return 0;
}