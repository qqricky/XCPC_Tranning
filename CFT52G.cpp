#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
//#pragma GCC optimise(2)
const int N=1e5+10;
using namespace std;
template<typename t>void read(t &x){
    char ch=getchar();x=0;int f=1;
	while(ch<'0' || ch>'9')	{if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int deg[1050]={};
bool vis[1050][1050]={};
vector<pair<int,int> >v[1050];
int ma[1050]={};
int pos[1050]={};
int de[1050]={};
bool vi[1050][1050]={};
int res[530][530]={};
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(1){
        int n,m;
        n=50;
        int val=n*(n-1)/2-1;
        m=rand()%val+1;
        set<pair<int,int> >s;
        memset(deg,0,sizeof(deg));
        memset(de,0,sizeof(de));
        memset(pos,0,sizeof(pos));
        memset(ma,0,sizeof(ma));
        memset(vis,0,sizeof(vis));
        memset(vi,0,sizeof(vi));
        for(int i=0;i<1050;i++)v[i].clear();
        int ans=2*n-2;
        for(int i=1;i<=m;i++){
            int x,y;
            x=rand()%n+1;
            y=rand()%n+1;
            if(x>y)swap(x,y);
            while((x==y)||s.count(make_pair(x,y))){
                x=rand()%n+1;
                y=rand()%n+1;
                if(x>y)swap(x,y);
            }
            s.insert(make_pair(x,y));
            vis[x][y]=1;
            vis[y][x]=1;
            deg[x]++;
            deg[y]++;
            de[x]++;de[y]++;
            vi[x][y]=vi[y][x]=1;
        }
        if(m==0){
            cout<<0;
            return 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(!vis[i][j]){
                    v[i].push_back(make_pair(j,deg[i]+deg[j]));
                    res[i][j]=res[j][i]=deg[i]+deg[j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            ma[i]=-1;
            for(int j=0;j<v[i].size();j++){
                auto pr=v[i][j];
                int val=pr.second;
                if(val>ma[i]){
                    ma[i]=val;
                    pos[i]=j;
                }
            }
        }
        int ress=INF;
        for(int q=1;q<=n*(n-1)/2-m;q++){
                int mm=-1;
                int xx,yy;
                for(int i=1;i<=n;i++){
                    for(int j=i+1;j<=n;j++){
                        if(!vi[i][j]){
                            if(de[i]+de[j]>mm){
                                mm=de[i]+de[j];
                                xx=i;
                                yy=j;
                            }
                        }
                    }
                }
                vi[xx][yy]=vi[yy][xx]=1;
                de[xx]++;
                de[yy]++;
                // cout<<mm<<' '<<xx<<' '<<yy<<endl;
                ress=min(ress,mm);
            }
            for(int q=1;q<=n*(n-1)/2-m;q++){
            int mx=-1;
            int po=0;
            for(int i=1;i<=n;i++){
                if(ma[i]>mx){
                    mx=ma[i];
                    po=i;
                }
            }
            while(mx<=0||po<=0){
                int kk=1;
                kk++;
            }
            ans=min(ans,ma[po]);
            while(ans<=0){
                int kk=1;
                kk++;
            }
            int x=po;
            // cout<<q<<endl;
            // cout<<po<<' '<<mx<<' '<<pos[po]<<endl;
            int y=v[po][pos[po]].first;
            // cout<<x<<' '<<y<<endl;
            // if(x==1&&y==2){
            //     cout<<"wahatsjlsdk\n";
            //     for(int i=1;i<=n;i++){
            //         cout<<ma[i]<<' ';
            //     }
            //     cout<<'\n';
            //     for(auto pr:v[1]){
            //         cout<<pr.first<<' '<<pr.second<<'\n';
            //     }
            //     cout<<"dsfajlkdfjlkasd\n";
            // }
            v[x].erase(v[x].begin()+pos[po]);
            for(int j=0;j<v[y].size();j++){
                if(v[y][j].first==x){
                    v[y].erase(v[y].begin()+j);
                    break;
                }
            }
            int maa=-1;
            int poo=0;
            // if(x==3&&y==4){
            //     cout<<"asdjfklk\n";
            //     cout<<v[x].size()<<'\n';
            // }
            for(int j=0;j<v[x].size();j++){
                int yy=v[x][j].first;
                v[x][j].second=max(res[x][yy],res[yy][x])+1;
                res[x][yy]=v[x][j].second;
                // cout<<"!@#  "<<x<<' '<<v[x][j].first<<'\n';
                // if(x==3&&y==4){
                //     cout<<"dsajkldfjl\n";
                //     cout<<v[x][j].first<<' '<<v[x][j].second<<'\n';
                // }
                auto pr=v[x][j];
                if(pr.second>maa){
                    maa=pr.second;
                    poo=j;
                }
            }
            int kk=1;
            ma[x]=maa;
            pos[x]=poo;
            maa=-1;
            poo=0;
            for(int j=0;j<v[y].size();j++){
                int yy=v[y][j].first;
                v[y][j].second=max(res[yy][y],res[y][yy])+1;
                res[y][yy]=v[y][j].second;
                // cout<<"!@       "<<y<<' '<<v[y][j].first<<'\n';
                auto pr=v[y][j];
                if(pr.second>maa){
                    maa=pr.second;
                    poo=j;
                }
            }
            ma[y]=maa;
            pos[y]=poo;
        }
        if(ress!=ans){
            cout<<"what "<<ress<<' '<<ans<<'\n';
            for(auto pr:s){
                cout<<pr.first<<' '<<pr.second<<"\n";
            }
            cout.flush();
            system("pause");
        }
    }
    //cout<<ans;
    cout.flush();
    //system("pause");
    return 0;
}