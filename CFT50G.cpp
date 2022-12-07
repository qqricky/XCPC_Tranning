#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=3e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
vector<pair<int,int> >line;
vector<pair<int,int> >row;
deque<pair<int,int> >li;
deque<pair<int,int> >ro;
// vector<int>rw;
// vector<int>ln;
int xx[N];
int yy[N];
// map<pair<int,int>,int>vis;
set<int>s[5];
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    int cnt=0;
    while(t--){
        for(int i=1;i<=4;i++){
            s[i].clear();
        }
        int n,m;
        cin>>n>>m;
        line.clear();
        row.clear();
        // vis.clear();
        while(li.size())li.pop_back();
        while(ro.size())ro.pop_back();
        int l1=1,l2=1;
        int r1=n,r2=n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            xx[i]=x;
            yy[i]=y;
            if(xx[i]==1&&yy[i]==1){
                s[1].insert(i);
            }
            else if(xx[i]==1&&yy[i]==n){
                s[2].insert(i);
            }
            else if(xx[i]==n&&yy[i]==1){
                s[4].insert(i);
            }
            else if(xx[i]==n&&yy[i]==n){
                s[3].insert(i);
            }
            row.push_back(make_pair(x,i));
            line.push_back(make_pair(y,i));
        }
        sort(row.begin(),row.end());
        sort(line.begin(),line.end());
        for(auto pr:row){
            ro.push_back(pr);
        }
        for(auto pr:line){
            li.push_back(pr);
        }
        int pos1=1;
        int pos2=1;
        int  nw=0;
        while(m--){
            char ch;
            int val;
            cin>>ch;
            if(ch=='!'){
                ll ans=0;
                if(l1==r1&&l2==r2){
                    ans=1ll*n*(n-1)/2;
                }
                else if(l2==r2){
                    while(s[2].size()){
                        s[1].insert(*s[2].begin());
                        s[2].erase(s[2].begin());
                    }
                    while(s[3].size()){
                        s[4].insert(*s[3].begin());
                        s[3].erase(s[3].begin());
                    }
                    if(s[4].size()>1){
                        ans+=1ll*s[4].size()*(s[4].size()-1)/2;
                    }
                    if(s[1].size()>1){
                        ans+=1ll*s[1].size()*(s[1].size()-1)/2;
                    }
                }
                else if(l1==r1){
                    while(s[4].size()){
                        s[1].insert(*s[4].begin());
                        s[4].erase(s[4].begin());
                    }
                    while(s[3].size()){
                        s[2].insert(*s[3].begin());
                        s[3].erase(s[3].begin());
                    }
                    if(s[2].size()>1){
                        ans+=1ll*s[2].size()*(s[2].size()-1)/2;
                    }
                    if(s[1].size()>1){
                        ans+=1ll*s[1].size()*(s[1].size()-1)/2;
                    }
                }
                else{
                    for(int i=1;i<=4;i++){
                        if(s[i].size()>1){
                            ans+=1ll*s[i].size()*(s[i].size()-1)/2;
                        }
                    }
                }
                // if(ans==2){
                //     cout<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<' ';
                //     for(int i=1;i<=4;i++)cout<<s[i].size();
                //     return 0;
                // }
                cout<<ans<<'\n';
                continue;
            }
            if(ch=='?'){
                int id;
                cin>>id;
                int x=xx[id];
                int y=yy[id];
                if(x<=l1)x=l1;
                if(x>=r1)x=r1;
                x=x-l1;
                if(y<=l2)y=l2;
                if(y>=r2)y=r2;
                y=y-l2;
                cout<<pos1+x<<' '<<pos2+y<<'\n';
                continue;   
            }
            cin>>val;
            if(ch=='D'){
                int tmp=pos1+(r1-l1+1)-1;
                int vv=val;
                val-=(n-tmp);
                int nr=r1;
                if(val>0){
                    nr=max(l1,r1-val);
                }
                while(ro.size()&&ro.back().first>=nr){
                    auto x=ro.back();
                    int id=x.second;
                    if(yy[id]<=l2){
                        s[4].insert(id);
                    }
                    if(yy[id]>=r2){
                        s[3].insert(id);
                    }
                    // if(ro.back().second<=l2||ro.back().second>=r2){
                    //     if(!vis[make_pair(ro.back().first,ro.back().second)]){
                    //         vis[make_pair(ro.back().first,ro.back().second)]=1;
                    //         cnt++;
                    //     }
                    // }
                    ro.pop_back();
                }
                pos1=min(pos1+vv,n);
                r1=nr;
            }
            else if(ch=='U'){
                int tmp=pos1;
                int vv=val;
                val-=(pos1-1);
                int nl=l1;
                if(val>0){
                    nl=min(r1,l1+val);
                }
                while(ro.size()&&ro.front().first<=nl){
                    auto x=ro.front();
                    int id=x.second;
                    if(yy[id]<=l2){
                        s[1].insert(id);
                    }
                    if(yy[id]>=r2){
                        s[2].insert(id);
                    }
                    // if(ro.front().first<=l1||ro.front().second>=r1){
                    //     if(!vis[make_pair(ro.back().second,ro.back().first)]){
                    //         vis[make_pair(ro.back().second,ro.back().first)]=1;
                    //         cnt++;
                    //     }
                    // }
                    ro.pop_front();
                }
                pos1=max(1,pos1-vv);
                l1=nl;
            }
            else if(ch=='R'){
                int tmp=pos2+(r2-l2+1)-1;
                int vv=val;
                val-=(n-tmp);
                int nr=r2;
                if(val>0){
                    nr=max(l2,r2-val);
                }
                while(li.size()&&li.back().first>=nr){
                    auto x=li.back();
                    int id=x.second;
                    if(xx[id]<=l1){
                        s[2].insert(id);
                    }
                    if(xx[id]>=r1){
                        s[3].insert(id);
                    }
                    // if(li.back().second<=l1||li.back().second>=r1){
                    //     if(!vis[make_pair(li.back().first,li.back().second)]){
                    //         vis[make_pair(li.back().first,li.back().second)]=1;
                    //         cnt++;
                    //     }
                    // }
                    li.pop_back();
                }
                pos2=min(pos2+vv,n);
                r2=nr;
            }
            else{
                int tmp=pos2;
                int vv=val;
                val-=(pos2-1);
                int nl=l2;
                if(val>0){
                    nl=min(r2,l2+val);
                }
                while(li.size()&& li.front().first<=nl){
                    // if(li.front().first<=l2||li.front().second>=r2){
                    //     if(!vis[make_pair(li.back().second,li.back().first)]){
                    //         vis[make_pair(li.back().second,li.back().first)]=1;
                    //         cnt++;
                    //     }
                    // }
                    auto x=li.front();
                    int id=x.second;
                    if(xx[id]<=l1){
                        s[1].insert(id);
                    }
                    if(xx[id]>=r1){
                        s[4].insert(id);
                    }
                    li.pop_front();
                }
                pos2=max(1,pos2-vv);
                l2=nl;
            }
            // cout<<"-----------------------\n";
            // cout<<l1<<' '<<r1<<'\n';
            // cout<<l2<<' '<<r2<<'\n';
            // cout<<"so "<<pos1<<' '<<pos2<<'\n';
        }
    }
    cout.flush();
    //system("pause");
    return 0;
}