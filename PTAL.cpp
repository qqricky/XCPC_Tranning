#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 0x3f3f3f3f
double eps=1e-5;
const int N=547;
int mp[N][N];
int f[N][N];
bool ism[N]={};
int n;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(mp,0x3f,sizeof(mp));
    for(int i=1;i<=n;i++)mp[i][i]=0;
    for(int i=1;i<=n;i++){
        char ch;
        cin>>ch;
        if(ch=='M')ism[i]=1;
        int m;
        cin>>m;
        for(int j=1;j<=m;j++){
            int x,y;
            cin>>x>>ch>>y;
            mp[i][x]=y;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=mp[i][j];
        }
    }
    floyd();
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<i<<"-->"<<j<<' '<<f[i][j]<<endl;
    //     }
    // }
    double mim=INF;
    double mif=INF;
    vector<int>ansm;
    vector<int>ansf;
    for(int i=1;i<=n;i++){
        int ma=-1;
        if(ism[i]){
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                if(ism[j])continue;
                //cout<<f[j][i]<<endl;
                ma=max(ma,f[j][i]);
            }
            double val=1.0/ma;
            if(ma==mim){
                ansm.push_back(i);
            }
            else if(ma<mim){
                mim=ma;
                ansm.clear();
                ansm.push_back(i);
            }
        }
        else{
            for(int j=1;j<=n;j++){
                if(j==i)continue;
                if(!ism[j])continue;
                ma=max(ma,f[j][i]);
            }
            double val=1.0/ma;
            if(ma==mif){
                ansf.push_back(i);
            }
            else if(ma<mif){
                mif=ma;
                ansf.clear();
                ansf.push_back(i);
            }
        }
    }
    for(int j=0;j<(int)ansf.size()-1;j++){
        cout<<ansf[j]<<' ';
    }
    cout<<ansf[(int)ansf.size()-1]<<'\n';
    for(int j=0;j<(int)ansm.size()-1;j++){
        cout<<ansm[j]<<' ';
    }
    cout<<ansm[(int)ansm.size()-1]<<'\n';
    cout.flush();
    //system("pause");
    return 0;
}