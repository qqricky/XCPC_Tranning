#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e5+10; 
using namespace std;
char mp[105][105];
int n,m;
ll cntt=0;
struct go
{
    vector<int>vv;
};
vector<go>v;
void change(int i,int j)
{   
    if(j==m)j--;
    if(i==n)i--;
    int x[5];
    x[1]=mp[i][j]-'0';mp[i][j]='0';
    x[2]=mp[i][j+1]-'0';mp[i][j+1]='0';
    x[3]=mp[i+1][j+1]-'0';mp[i+1][j+1]='0';
    x[4]=mp[i+1][j]-'0';mp[i+1][j]='0';
    map<int,pair<int,int>>to;
    to[1]=make_pair(i,j);
    to[2]=make_pair(i,j+1);
    to[3]=make_pair(i+1,j+1);
    to[4]=make_pair(i+1,j);
    int cnt=0;
    for(int k=1;k<=4;k++)cnt+=x[k];
    //cout<<'i'<<i<<'j'<<j<<"cnt   "<<cnt<<endl;
    if(cnt==0)return;
    else if(cnt==3){
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(x[k]){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
            }
        }
        //cout<<endl;
    }
    else if(cnt==2){
        int flag=0;
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(x[k]==0){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
            }
            else if(!flag){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
                flag=k;
            }
        }
        cntt++;
        v.push_back((go){});
        //cout<<endl;
        for(int k=1;k<=4;k++){
            if(k==flag)continue;
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
            //cout<<to[k].first<<' '<<to[k].second<<' ';
        }
        //cout<<endl;
    }
    else if(cnt==1){
        int cn=0;
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(x[k]==0&&cn>=2)continue;
            if(x[k]==0){cn++;x[k]=1;}
            else{
                x[k]=0;
            }
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
            //cout<<to[k].first<<' '<<to[k].second<<' ';
        }
        //cout<<endl;
        cntt++;
        v.push_back((go){});
        int flag=0;
        for(int k=1;k<=4;k++){
            if(x[k]==0){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
            }
            else if(!flag){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
                flag=k;
            }
        }
        //cout<<endl;
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(k==flag)continue;
            //cout<<to[k].first<<' '<<to[k].second<<' ';
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
        }
        //cout<<endl;
    }
    else{
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=3;k++){
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
            //cout<<to[k].first<<' '<<to[k].second<<' ';
            x[k]=0;
        }
        //cout<<endl;
        int cn=0;
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(x[k]==0&&cn>=2)continue;
            if(x[k]==0){cn++;x[k]=1;}
            else{
                x[k]=0;
            }
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
            //cout<<to[k].first<<' '<<to[k].second<<' ';
        }
        //cout<<endl;
        cntt++;
        v.push_back((go){});
        int flag=0;
        for(int k=1;k<=4;k++){
            if(x[k]==0){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
            }
            else if(!flag){
                v[cntt].vv.push_back(to[k].first);
                v[cntt].vv.push_back(to[k].second);
                //cout<<to[k].first<<' '<<to[k].second<<' ';
                flag=k;
            }
        }
        //cout<<endl;
        cntt++;
        v.push_back((go){});
        for(int k=1;k<=4;k++){
            if(k==flag)continue;
            //cout<<to[k].first<<' '<<to[k].second<<' ';
            v[cntt].vv.push_back(to[k].first);
            v[cntt].vv.push_back(to[k].second);
        }
        //cout<<endl;
        //cout<<endl;
    }
}
int main()
{
    //freopen("TestCase.in","r",stdin);
    //freopen("TestCase.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        v.clear();
        v.push_back((go){});
        cntt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
            }
        }
        for(int i=1;i<=n;i+=2){
            for(int j=1;j<=m;j+=2){
                change(i,j);
            }
        }
        cout<<cntt<<endl;
        for(int i=1;i<=cntt;i++){
            for(int j=0;j<6;j++){
                cout<<v[i].vv[j]<<' ';
            }
            v[i].vv.clear();
            cout<<endl;
        }
    }
    //system("pause");
    return 0;
}